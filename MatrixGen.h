#ifndef MATRIXGEN_H
#define MATRIXGEN_H

#include <vector>
#include "bitbangM.h"

// The interface
int generate_solutions_M(int N);

// Helper functions
bool _seemsValidSolution(CBBMatrix& M);
std::vector<int>* _matrixToSolution(CBBMatrix& M);


#endif /* MATRIXGEN_H */