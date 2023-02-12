#include "Rational.h"
int main() {
	Rational r(1, 3);
	Rational b(1, 2);
	r -= b;
	r.reducing();
	std::cout << 8;
}