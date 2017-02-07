#include <stdlib.h> 
#include <stdio.h>
#include <string> 
#include <iomanip>  

#include "bigint/BigIntegerLibrary.hh"
#include "MatrixGen.h"
#include "GTGen.h"
#include "PermutationsGen.h"



void print_usage()
{
	std::cerr << "Usage: cvrp_gen_cpp [<N>] [<method>]" << std::endl;
	std::cerr << " where <N> is the number of customers" << std::endl;
	std::cerr << " where <method> is the generation method \"matrix\"/\"giant_tours\"/\"permutations\"" << std::endl;
}

/*
 Enumerates all solutions and prints them (if compiled with PRINT_SOLUTIONS), 
  otherwise just print the number of generated solutions.
*/
int main(int argc, char **argv)
{
	unsigned long long possible_sols = 0;

	int N = 3;
	std::string method = "permutations";
	if (argc == 0)
	{
		print_usage();
		std::cerr << "Running with defaults N=" << N <<" method=" << method << std::endl;
	}	
	if (argc > 1)
	{
		N = atoi(argv[1]);
		if (N<=0)
		{
			print_usage();
			exit(-1);
		}
	}
	if (argc > 2)
		method = std::string(argv[2]);
	
	if (method == "matrix")
	{
		possible_sols = generate_solutions_M(N);
	}
	else if (method == "giant_tours")
	{
		possible_sols = generate_solutions_gt(N);
	}
	else if (method == "permutations")
	{
		possible_sols = generate_solutions_P(N);
	}
	else 
	{
		std::cerr << "Unknown generation method " << method << "!" <<std::endl;
		print_usage();
		exit(-1);
	}
#ifndef PRINT_SOLUTIONS
	std::cout << std::setprecision(30) << possible_sols << std::endl;
#endif
#ifdef _DEBUG
	getchar();
#endif
}
