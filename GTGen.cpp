#include "GTGen.h"

#include <iostream>
#include <stdlib.h> 
#include <stdio.h>
#include <algorithm>

#include "includes.h"
#include "bigint/BigIntegerLibrary.hh"

/*
In this file a giant tour and hamiltonian cyles based recursive solution
generator for enumeration of all feasible solutions to a unconstrained
VRP is presented. 

TODO: improve by using a double linked list
*/

void _print_solution(Solution& rsol, bool first = false)
{
	if (!first)
		std::cout << std::endl;
	
	std::cout << "[";
	Solution_iter last = (++rsol.rbegin()).base();
	for(Solution_iter i=rsol.begin(); i != rsol.end(); ++i)
	{
		std::cout << (*i);
		if (i!=last)
			std::cout << ",";
	}
	std::cout << "]";
}

/*
The actual generation procedure that takes a hamiltonian cycle fullTour
 and splits it to routes leaving and returning to depot in all possible
 ways. fromIdx and toIdx are used by the recusion to set the section
 of the giant tour that is modified.
*/
unsigned long long _gen_routes(Solution& fullTour, int fromIdx, int toIdx)
{
    if (toIdx-fromIdx<2)
	{
        // 0->1->0, no more splitting to do!
        return 0;
	}
 
	unsigned long long solution_count = 0;
	int tlen = fullTour.size();
	for(int putIdx=fromIdx; putIdx<toIdx+1 ; ++putIdx)
	{
	
        //# The condition rows check following things:
        //# 1. Prevent empty routes (from 0 to 0)
        //# 2. Route start smaller than end for the route before putIdx
        //# 3. Route start smaller than end for the route after putIdx
        //# 4. Created routes are in right order
        //# 5. Next route start must be bigger
        
        // DEBUG:
        //[fullTour[i] for i in xrange(fromIdx, toIdx)], "of", fullTour, "at", putIdx
        //"c1", fullTour[putIdx]!=0 and fullTour[putIdx+1]!=0
        //"c2", fullTour[fromIdx+1]<=fullTour[putIdx]
        //"c3", putIdx+1<len(fullTour) and fullTour[putIdx+1]<=fullTour[toIdx-1]
        //"c4", putIdx+1<len(fullTour) and fullTour[fromIdx+1]<=fullTour[putIdx+1]
        //"c5", toIdx+1>=len(fullTour) or fullTour[putIdx+1]<=fullTour[toIdx+1]
        
        if ( fullTour[putIdx]!=0 && fullTour[putIdx+1]!=0 && /*c1*/
             fullTour[fromIdx+1]<=fullTour[putIdx] && /*c2*/
             fullTour[putIdx+1]<=fullTour[toIdx-1] && /*c3*/
             fullTour[fromIdx+1]<=fullTour[putIdx+1] && /*c4*/
             (toIdx+1>=tlen || fullTour[putIdx+1]<=fullTour[toIdx+1]) ) /*c5*/
		{
            
			// have no idea if this is the fast way of copying vector and 
			//  adding 0 to the middle. Should be unless STL is funny?
            Solution newRoute;
			newRoute.reserve(tlen+1);
			
			Solution_iter nth = fullTour.begin() + (putIdx+1);
			
			newRoute.insert(newRoute.end(), fullTour.begin(), nth);
			newRoute.push_back(0);
			newRoute.insert(newRoute.end(), nth, fullTour.end());
#ifdef PRINT_SOLUTIONS			            
			_print_solution(newRoute);
#endif      
            solution_count+=1; // the one inserted above
			solution_count+=_gen_routes(newRoute, fromIdx, putIdx+1); // the ones before the insertion pt
			solution_count+=_gen_routes(newRoute, putIdx, toIdx); // the ones after the insertion pt
            
			// NOTE: The 5 conditions above will take care there is no collisions.
		}
	}
	return solution_count;
} 


/*
This is a gian tour and hamiltonian cycle based generator of VRP
 solutions. It uses std::next_permutation on point sequences and
 a giant tour (GT) endcoding of solutions to enumerate all valid
 solutions to a VRP.
*/
unsigned long long generate_solutions_gt(int N)
{
	bool first_print = true;
	unsigned long long solution_counter = 0;
	
	//std::cout << "["; // << std::endl;
	
	Solution pm;
	pm.reserve(N+1);
	for (int i = 1; i<N+1; ++i)
		pm.push_back(i);
	
	// Create all Possible giant tours
    
	Solution_iter pm_start = pm.begin();
    Solution_iter pm_end = pm.end();
    
	do 
	{
        // Ordered so that the first is always smaller than the last
		Solution_iter first = pm.begin();
		Solution_iter last = (++pm.rbegin()).base();
        if ((*first)<=(*last))
		{
			Solution giant_tour_solution;
			giant_tour_solution.reserve(N+2);
			
			giant_tour_solution.push_back(0);
			giant_tour_solution.insert(giant_tour_solution.end(),pm.begin(), pm.end());
			giant_tour_solution.push_back(0);

#ifdef PRINT_SOLUTIONS	
			_print_solution(giant_tour_solution, first_print);
#endif
			solution_counter++;
			
			first_print = false;
		
			// std::cerr << "generating for giant tour " << str(gt) << std::endl;
			solution_counter+=_gen_routes(
				giant_tour_solution,
				0, 
				N+1 );
		}
    } while (std::next_permutation(pm_start, pm_end)); //pm in permutations(range(1,N+1), N)
    
#ifdef PRINT_SOLUTIONS		
	std::cout << std::endl;
#endif
	//std::cout << "]" << std::endl;
    //return solutions
	
	return solution_counter;
}
