#include "PermutationsGen.h"
#include "includes.h"
#include "PermutationAndConmbinationHelpers.h"

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm> 


#define vint std::vector<int>::size_type
/* A permutations based generator of solutions 
to a unconstrained VRP is presented here.

Usage:
solutions is a list of routes in form
and N is number of customers in the VRP
*/


int _permutations_of_remaining(int N,
	vint non_degenerate_route_count, // without the single customer routes
	std::vector<int>& route_starts,
	std::vector<int>& route_ends,
	std::vector<int>& remaining_nodes)
{
	vint remaining_count = remaining_nodes.size();
	vint route_count = route_starts.size();

	if (remaining_count==0)
	{
		// the degenerate case of each trip consisting of a single customer
#ifdef PRINT_SOLUTIONS
		std::cout << "[";
		for (vint i = 0; i<route_count; ++i){
			std::cout << "0," << route_starts[i] << ",";
			if (route_starts[i] != route_ends[i]) std::cout << route_ends[i] << ",";
		}
		std::cout << "0]" << std::endl;
#endif
		return 1;
	}

	int nsols = 0;
	do {
		// Go trough all possible divisions of remaining nodes
		//  to the routes of route_start_nodes.
		// route_designator contains idxs of the routes the
		//  remaining nodes belong to.
		
		std::vector<int> route_designator(remaining_count, 0);
		RouteDesignatorPermutator designator_permutator(route_designator, remaining_count, non_degenerate_route_count);
		do
		{
			// Build the route
			// 1) starting from route_start
			// 2) with remaining nodes distributed to non degenerate routes
			//     (more than one customer) according to route_designator 
			// 3) eding to the route_end

			// the solution with a right number of 0s (visit to depot)
			Solution new_route(N + route_count + 1, 0);
			int pos = 1;
			
			int nondg_route_idx = 0; // add remaining to routes that are not single customer routes
			for (vint route_idx = 0; route_idx < route_count; ++route_idx){
				new_route[pos++] = route_starts[route_idx];
				if (route_starts[route_idx] != route_ends[route_idx])
				{
					for (vint remaining_idx = 0; remaining_idx < remaining_count; ++remaining_idx){
						if (route_designator[remaining_idx] == nondg_route_idx)
						{
							new_route[pos++] = remaining_nodes[remaining_idx];
						}
					}
					nondg_route_idx++;
					new_route[pos++] = route_ends[route_idx];
				}
				new_route[pos++] = 0;
			}
			
			//new_route.resize(pos);
			nsols++;
#ifdef PRINT_SOLUTIONS
			Solution_size ssize = new_route.size();
			std::cout << "[";
			for (Solution_size i = 0; i<ssize; ++i){
				std::cout << new_route[i];
				if (i != ssize - 1)
					std::cout << ",";
			}
			std::cout << "]";
			std::cout << std::endl;
#endif
		} while (designator_permutator.next_designator());
	} while (std::next_permutation(remaining_nodes.begin(), remaining_nodes.end()));
	return nsols;
}

int generate_solutions_P(int N)
{
	int nsols = 0;
	
	for (vint number_of_routes = 1; number_of_routes != N + 1; number_of_routes++) {
		// All possible ways of starting the 

		CnCr choose_tour_starts(N, number_of_routes);
		std::vector<int>* tour_starts = choose_tour_starts.choose_next_K_from_N();
		while (tour_starts != NULL)
		{
			std::vector<int>* remaining_for_end_nodes = choose_tour_starts.those_not_in_K_from_N();
			RouteEndPermutator route_end_permutator(N, number_of_routes);
			if (route_end_permutator.initialize_permutator(*remaining_for_end_nodes, *tour_starts))
			{
				// enumerate all permutations of the tour ends
				do {
					int nondegenerate_route_count = route_end_permutator.get_nondegenerate_route_count();
					std::vector<int>* tour_ends = route_end_permutator.get_end_nodes();

					// Make a list of the remaining nodes (those not used as an end)
					std::vector<bool> used_as_end(N + 1, false);
					std::vector<int>* remaining = new std::vector<int>(remaining_for_end_nodes->size(), 0);
					int remaining_count = 0;
					for (vint ri = 0; ri < number_of_routes; ri++)
					{
						int current_end = (*tour_ends)[ri];
						used_as_end[current_end] = true;
					}
					for (std::vector<int>::iterator it = remaining_for_end_nodes->begin(); it != remaining_for_end_nodes->end(); ++it)
					{
						if (!used_as_end[(*it)]) (*remaining)[remaining_count++] = (*it);
					}
					remaining->resize(remaining_count);

#ifdef _DEBUG
					std::cout << std::endl << "Generate permutations for a configuration";
					std::cout << std::endl << "starts: [";
					for (vint i = 0; i < tour_starts->size(); ++i)
						std::cout << (*tour_starts)[i] << (i == tour_starts->size() - 1 ? "" : ",");
					std::cout << "]" << std::endl << "  ends: [";
					for (vint i = 0; i < tour_ends->size(); ++i)
						std::cout << (*tour_ends)[i] << (i == tour_ends->size() - 1 ? "" : ",");
					std::cout << "]" << std::endl << "  rest: [";
					for (vint i = 0; i < remaining->size(); ++i)
						std::cout << (*remaining)[i] << (i == remaining->size() - 1 ? "" : ",");
					std::cout << "]" << std::endl;
#endif
					nsols += _permutations_of_remaining(N, nondegenerate_route_count,
						*tour_starts, *tour_ends, *remaining);

					delete remaining;
					delete tour_ends;
				} while (route_end_permutator.next_permutation());
			}
#ifdef _DEBUG
			else
			{
				std::cout << std::endl << "Rejected a configuration with";
				std::cout << std::endl << "starts: [";
				for (vint i = 0; i < tour_starts->size(); ++i)
					std::cout << (*tour_starts)[i] << (i == tour_starts->size() - 1 ? "" : ",");
				std::cout << "]" << std::endl << "  rest: [";
				for (vint i = 0; i < remaining_for_end_nodes->size(); ++i)
					std::cout << (*remaining_for_end_nodes)[i] << (i == remaining_for_end_nodes->size() - 1 ? "" : ",");
				std::cout << "]" << std::endl;
			}
#endif

			delete remaining_for_end_nodes;
			delete tour_starts;
			tour_starts = choose_tour_starts.choose_next_K_from_N();
		}
	}

#ifdef PRINT_SOLUTIONS
	std::cout << std::endl;
#endif
	return nsols;
}