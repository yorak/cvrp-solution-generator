#ifndef BITBANGM_H
#define BITBANGM_H

/* This file describes the API of an boolean symmetric matrix */

#include "bigint/BigUnsigned.hh"
#include <iostream>

class CBBMatrix {
private:
	int _N;
	BigUnsigned _M;
	BigUnsigned* _bitmasks;
	BigUnsigned  _last_value;
	
	int get_mask_idx(const int i, const int j);
public:
	CBBMatrix(int N);
	~CBBMatrix();
	
	int length();
	void print(std::ostream& io);
    bool next_value();
	void jump_to_next_change_in(const int i, const int j);
    
    bool get_value(const int i, const int j);
	void set_value(const int i, const int j, const bool value);
	void set_value(const int i, const int j, const int value);
};

#endif /* BITBANGM_H */