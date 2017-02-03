#include "PermutationAndConmbinationHelpers.h"
#include <vector>
#include <algorithm> 

CnCr::CnCr(int fromN, int takeK)
{
	N = fromN;
	K = takeK;
	first = true;
	pBitmask = new std::vector<bool>(K, true); // K leading 1's
	pBitmask->resize(N, false); // N-K trailing 0's
}

CnCr::~CnCr()
{
	delete pBitmask;
}

// Adapted from
//  http://rosettacode.org/wiki/Combinations#C.2B.2B
std::vector<int>* CnCr::choose_next_K_from_N()
{
	if (first || std::prev_permutation(pBitmask->begin(), pBitmask->end()))
	{
		first = false;

		std::vector<int>* pChoise = new std::vector<int>(K);
		int j = 0;
		for (int i = 0; i < N; ++i) // [0..N-1] integers
		{
			if ((*pBitmask)[i])
			{
				(*pChoise)[j] = i+1; // 1 based indexing of results
				j++;
			}
		}
		return pChoise;
	}
	else
	{
		return NULL;
	}
}

std::vector<int>* CnCr::those_not_in_K_from_N()
{
	if (!first)
	{
		std::vector<int>* pNotChosen = new std::vector<int>(N-K);
		int j = 0;
		for (int i = 0; i < N; ++i) // [0..N-1] integers
		{
			if (!(*pBitmask)[i])
			{
				(*pNotChosen)[j] = i + 1; // 1 based indexing of results
				j++;
			}
		}
		return pNotChosen;
	}
	else
	{
		return NULL;
	}
}



RouteDesignatorPermutator::RouteDesignatorPermutator(std::vector<int>& designator_to_permute, int nodes, int routes)
	: rDesignator(designator_to_permute)
{
	node_count = nodes;
	route_count = routes;
	inc_pos = 0;
}

/*
This designates the remaining nodes on the routes. The designator has a constraint
d_i<d_j \forall i<j, because all possible permutations of the remaining nodes are
listed and unless this constraint there would be duplicates.
*/
bool RouteDesignatorPermutator::next_designator()
{
	// Reached the end, reset backwards
	if (inc_pos + 1 >= node_count)
	{
		inc_pos = node_count - 1;
		int baseline = rDesignator[inc_pos];

		while (inc_pos != 0 && rDesignator[inc_pos - 1] <= baseline)
		{
			rDesignator[inc_pos] = 0;
			inc_pos--;
		}
	}

	// increment designator by one and if there is even a single overflow, abort
	if (++(rDesignator[inc_pos++]) >= route_count)
	{
		return false;
	}

	return true;
}


RouteEndPermutator::RouteEndPermutator(int nodes, int routes)
	: node_count(nodes), route_count(routes), current_nondegenerate_route_count(routes), valid_end_nodes_for_routes(routes), current_route_end_nodes(routes), route_starts(NULL)
{
}

bool RouteEndPermutator::initialize_permutator(std::vector<int>& remaining_nodes, std::vector<int>& start_nodes)
{
	route_starts = &start_nodes;

	for (std::vector<int>::iterator it = remaining_nodes.begin(); it != remaining_nodes.end(); ++it) {
		for (int ri = 0; ri < route_count; ri++)
		{
			if (start_nodes[ri] < *it)
			{
				valid_end_nodes_for_routes[ri].push_back(*it);
			}
		}
	}

	for (int ri = 0; ri < route_count; ri++)
	{
		valid_end_nodes_for_routes[ri].push_back(start_nodes[ri]);
		current_route_end_nodes[ri] = valid_end_nodes_for_routes[ri].begin();

		int current_end_node = *current_route_end_nodes[ri];
		if (current_end_node == start_nodes[ri])
		{
			current_nondegenerate_route_count--;
		}
	}
	return find_first_valid_permutation();
}


std::vector<int>* RouteEndPermutator::get_end_nodes()
{
	std::vector<int>* new_ends = new std::vector<int>(route_count, 0);
	for (int ri = 0; ri < route_count; ri++)
	{
		// collect current route ends to the new node end vector
		(*new_ends)[ri] = (*(current_route_end_nodes[ri]));
	}
	return new_ends;
}

int RouteEndPermutator::get_nondegenerate_route_count()
{
	return current_nondegenerate_route_count;
}

bool RouteEndPermutator::find_first_valid_permutation()
{
	// check that no end is used twice and there is at least one nondegenerate
	current_nondegenerate_route_count = route_count;
	std::vector<bool> taken(node_count + 1, false);
	for (int ri = 0; ri < route_count; ri++)
	{
		int end = (*(current_route_end_nodes[ri]));
		// If this end node is already taken, skip this permutation
		if (taken[end]) return next_permutation();
		taken[end] = true;

		if (end == (*route_starts)[ri])
		{
			current_nondegenerate_route_count--;
		}
	}
	// Skip the permutations with all degenerate routes
	if (current_nondegenerate_route_count == 0 && node_count - route_count > 0)
	{
		return next_permutation();
	}
	// no doubly used end nodes and some non-degenerate routes to fill with remaining
	return true;
}

bool RouteEndPermutator::next_permutation()
{
	current_route_end_nodes[0]++;
	int carry_idx = 0;
	while (current_route_end_nodes[carry_idx] == valid_end_nodes_for_routes[carry_idx].end())
	{
		current_route_end_nodes[carry_idx] = valid_end_nodes_for_routes[carry_idx].begin();
		if (++carry_idx >= route_count)
		{
			return false;
		}
		current_route_end_nodes[carry_idx]++;
	}
	// check if this permutation is valid, and if not, call next_permutation again
	return find_first_valid_permutation();
}
