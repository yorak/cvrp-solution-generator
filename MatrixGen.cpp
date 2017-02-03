#include "MatrixGen.h"

#include <stdio.h>
#include <vector>

#include "bitbangM.h"
#include "includes.h"

/*
 Validates some constraints of the solution:
 - that every customer node has a degree of 2 
	or 1 (tour visits just one customer)
 - there must be enough edges leaving the depot
 - the chains are connected

 This is just the first (fast) phase of constraint validation
  the rest of the constraint validation is done in matrixToSolution
*/
bool _seemsValidSolution(CBBMatrix& M)
{
    int i = 0;
	int j = 0;
	int sumr = 0;
	int K = M.length();
    
    for (i=K-1 ; i>=0 ; i-- )
	{
        sumr = 0;
        for (j=K-1 ; j>=0 ; j-- )
		{
            sumr += M.get_value(i,j);
			
			if (i!=0 && sumr>2)
			{
				M.jump_to_next_change_in(i,j);
#ifdef _DEBUG
				std::cerr << "DEBUG: Rejected: Degree of 3 or more " << i << ", " << sumr << std::endl;
#endif
				return false;			
			}
		}
		
#ifdef _DEBUG
		std::cerr << "row " << i << " sum " << sumr << std::endl;
#endif

        // Tour must go trough depot
        if (i==0)
		{
            if (sumr==0 || (K>2 && sumr==1)) // TODO: K>=2 ??
			{
#ifdef _DEBUG
                std::cerr << "DEBUG: Rejected: No routes through depot" << i << ", " << sumr << std::endl;
#endif
                return false;
			}
		}
        else
		{
			if (sumr==0)
			{
				M.jump_to_next_change_in(i,0);
#ifdef _DEBUG
				std::cerr << "DEBUG: Rejected: Not connected " << i << ", " << sumr << std::endl;
#endif
				return false;			
			}
			if (!M.get_value(i,0) && sumr!=2)
			{
				M.jump_to_next_change_in(i,0);
#ifdef _DEBUG
				std::cerr << "DEBUG: Rejected: Deadend " << i << ", " <<  sumr << std::endl;
#endif
				return false;
			}
			// else if (M.get_value(i,0)) -> sumr=0-2
		}
	}
				
    return true;
}
            
Solution* _matrixToSolution(CBBMatrix& M)
{
    int i = 0;
	int j = 0;
	int K = M.length();
	
    
    int source = 0;
	int sink = 0;
    int served = 0;
    Solution* solution = new Solution();
	
    bool* exitUsed = new bool[K];
	for (i=0 ; i<K ; i++ )
	{
		exitUsed[i] = false;
	}
	
    for (i=0 ; i<K ; i++ )
	{
	    // This route has not been explored
        if (!exitUsed[i] && M.get_value(i,0))
		{
            //# Follow route
            solution->push_back(0);
            
            source = 0;
            sink = i;
            exitUsed[i] = true;
            
            while (sink!=0)
			{
                for (j=0 ; j<K+1 ; j++ )
				{
                    // Special case of back and forth to single node
                    if (j == K)
					{
                        source = sink;
                        sink = 0;
					}
                    // Follow the route
                    else if (M.get_value(sink,j) && j!=source)
					{
                        source = sink;
                        sink = j;
                        break;
					}
				}
                solution->push_back(source);
                served+=1;
			}
            
            exitUsed[source] = true;
		}
	}
    solution->push_back(0);
    
    if (served==K-1)
	{
        return solution;
	}
    else
	{
		delete solution;
        return NULL;
	}
}

int generate_solutions_M(int N)
{
	CBBMatrix M(N+1);
	Solution* psol = NULL;
	int nsols = 0;
		
    while (M.next_value())
	{
		//M.print(std::cout);

        if (_seemsValidSolution(M))
		{
            psol = _matrixToSolution(M);
            if (psol != NULL)
			{
#ifdef PRINT_SOLUTIONS
				if (nsols != 0)
				{
					std::cout << std::endl;
				}
				Solution& rsol = *psol;
				Solution_size ssize = rsol.size();
				std::cout << "[";
                for(Solution_size i=0; i<ssize ; ++i){
					std::cout << rsol[i];
					if (i!=ssize-1)
						std::cout << ",";
				}
				std::cout << "]";
#endif
				delete psol;
				nsols++;
			}
        }
	}
#ifdef PRINT_SOLUTIONS
	std::cout << std::endl;
#endif
	return nsols;
}