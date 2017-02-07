/* This file describes the API of an boolean symmetric matrix */

#include "bigint/BigIntegerLibrary.hh"
#include "bitbangM.h"
	
CBBMatrix::CBBMatrix(int N) :
_N(N), _M(0), _bitmasks(NULL), _last_value(0)
{
	/* In this implementation the boolean matrix is
        stored into one big integer with bitmasks used to address locations.
        order is, first the strictly upper corner matrix row by row, then
        the diagonal. For example N=4 matrix would be indexed as follows:
         
         x/y| 0 1 2 3      
         ---+---------
          0 | 6 0 1 2
          1 | 0 7 3 4
          2 | 1 3 8 5
          3 | 2 4 5 9
    */
	
	int i = 0;
	int j = 0;
	int idx = 0;
	BigUnsigned mask = 1;
	int mask_count =  (N*(N+1)/2);
	
	
	// Dynamic allocation of bitmask table
	_bitmasks = new BigUnsigned[mask_count];
	
	
	// Strictly upper corner masks
	for (i = 0 ; i < N ; i++)
	{
		for (j = i+1 ; j < N ; j++)
		{
			_last_value |= mask;
			idx = get_mask_idx(i,j);
			_bitmasks[idx] = mask;
			//std::cerr << "DEBUG: set mask ("<< i << "," << j <<" at " << idx << " to value " << bigUnsignedToString(mask) << std::endl;
			mask = mask << 1;
		}
	}
		
	// Diagonal masks
	for (i = 0 ; i < N ; i++)
	{
		idx = get_mask_idx(i,i);
		_bitmasks[idx] = mask;
		//std::cerr << "DEBUG: set mask ("<< i << "," << j <<" at " << idx << " to value " << bigUnsignedToString(mask) << std::endl;
		mask = mask << 1;
	}
}

CBBMatrix::~CBBMatrix()
{
	delete [] _bitmasks;
}
	
int CBBMatrix::length()
{
	return _N;
}


void CBBMatrix::print(std::ostream& iout)
{
	int i = 0;
	int j = 0;
	
	iout << "M = [" << std::endl;
	
    for (i = 0 ; i < _N ; i++)
	{
		for (j = 0 ; j < _N ; j++)
		{
            iout << (int)(get_value(i,j));
			if (i!=_N-1 || j!=_N-1 )
				iout << ", ";
		}
        iout << std::endl;
	}
	iout << "]" << std::endl;
}

bool CBBMatrix::next_value()
{
	if (_M == _last_value)
	{
		return false;
	}
	else
	{
		_M+=1;
		return true;
	}
}

void CBBMatrix::jump_to_next_change_in(const int i, const int j)
{
	// Set all prior to (i,j) to 1 so that the next call of 
	//  next_value() will change (i,j).
	int loop_idx = get_mask_idx(i, j)-1;
	while (loop_idx>=0)
	{
		_M |= _bitmasks[loop_idx];
		--loop_idx;
	}
}


int CBBMatrix::get_mask_idx(const int i, const int j)
{
	if (i==j)
	{
		return (_N*(_N-1)/2)+i;
	}
    else if (i>j)
	{
		return j*(_N-1)-int(j*(j+1)/2)+(i-1);
	}
	else
	{
		return i*(_N-1)-int(i*(i+1)/2)+(j-1);
	}
}
    

bool CBBMatrix::get_value(const int i, const int j)
{
	return ((_M & _bitmasks[get_mask_idx(i, j)]) != 0);
}

void CBBMatrix::set_value(const int i, const int j, const bool value)
{
	if (value)
	{
		_M |= _bitmasks[get_mask_idx(i,j)];
	}
	// Is set but asked to reset
	else if (get_value(i, j))
	{
		_M-=_bitmasks[get_mask_idx(i,j)];
	}
}

void CBBMatrix::set_value(const int i, const int j, const int value)
{
	set_value(i, j, value!=0);
}