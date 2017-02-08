#ifndef CNCR_H
#define CNCR_H

#include <vector>
#include <list>

class CnCr
{
private:
	std::vector<bool>* pBitmask;
	bool first;
	int N;
	int K;
public:
	CnCr(int fromN, int takeK);
	~CnCr();

	/* Get next combination until NULL, that is there is none left */
	std::vector<int>* choose_next_K_from_N();
	std::vector<int>* those_not_in_K_from_N();
};

class RouteDesignatorPermutator
{
private:
	std::vector<int>& rDesignator;
	int node_count;
	int route_count;
	int inc_pos;
public:
	RouteDesignatorPermutator(std::vector<int>& designator_to_permute, int nodes, int routes);
	bool next_designator();
};


class RouteEndPermutator
{
private:
	std::vector<int>* route_starts;
	std::vector< std::list<int> > valid_end_nodes_for_routes;
	std::vector< std::list<int>::iterator > current_route_end_nodes;
	int current_nondegenerate_route_count;
	int node_count;
	int route_count;
	// helper method that validates the current configuration and advances
	//  with next_permutation until a valid is found.
	bool is_valid_permutation();
public:
	RouteEndPermutator(int nodes, int routes);
	bool initialize_permutator(std::vector<int>& remaining_nodes, std::vector<int>& start_nodes);
	std::vector<int>* get_end_nodes();
	int get_nondegenerate_route_count();
	// skips all degerate configurations and 
	bool next_valid_permutation();
};


#endif /*CNCR_H*/