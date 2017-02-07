#ifndef MATRIXGEN_H
#define MATRIXGEN_H

#include "includes.h"
#include "bitbangM.h"

// The interface
unsigned long long generate_solutions_M(int N);

// Helper functions
bool _seemsValidSolution(CBBMatrix& M);
std::vector<int>* _matrixToSolution(CBBMatrix& M);


#endif /* MATRIXGEN_H */