#include "Rational.h"
#include<iostream>
int main() {
	
	Rational b(1,0);
	Rational r(5);
	r += b;
	

	
	
	std::cout << r;
	return 0;
}