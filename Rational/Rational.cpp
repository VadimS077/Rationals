// Rational.cpp: определяет точку входа для приложения.
//

#include "Rational.h"
	
Rational::Rational() {}
Rational::Rational(int n) {
	num = n;
	denom = 1;
}
Rational::Rational(int n, int d) {
	num = n;
	denom = d;
}
int Rational::nod(int n, int d) {
	num = n;
	denom = d;
	while (num && denom)
		if (num > denom) num %= denom;
		else denom %= num;
	return num + denom;
}
Rational& Rational::reducing() {
	int dev = nod(num,denom);
	num /= dev;
	denom /= dev;
	return *this;
}
Rational& Rational::operator=(const Rational& rhs) {
	num = rhs.num;
	denom = rhs.denom;
	return *this;
}
Rational& Rational::operator+=(const Rational& rhs) {
	num = num * rhs.denom + rhs.num * denom;
	denom = denom * rhs.denom;
	
	Rational r(num,denom);
	r.reducing();
	return *this;
}
Rational& Rational::operator-=(const Rational& rhs) {
	num = num * rhs.denom - rhs.num * denom;
	denom = denom * rhs.denom;

	Rational r(num, denom);
	r.reducing();
	return *this;
}
Rational& Rational::operator*=(const Rational& rhs) {
	num = num * rhs.num;
	denom = denom * rhs.denom;

	Rational r(num, denom);
	r.reducing();
	return *this;
}
Rational& Rational::operator/=(const Rational& rhs) {
	num = num * rhs.denom;
	denom = denom * rhs.num;

	Rational r(num, denom);
	r.reducing();
	return *this;
}
Rational operator+(Rational lhs, const Rational& rhs) {
	lhs += rhs;
	return lhs;
}
Rational operator-(Rational lhs, const Rational& rhs) {
	lhs -= rhs;
	return lhs;
}
Rational operator*(Rational lhs, const Rational& rhs) {
	lhs *= rhs;
	return lhs;
}
Rational operator/(Rational lhs, const Rational& rhs) {
	lhs /= rhs;
	return lhs;
}
bool Rational::zero() {
	return num == 0;
}
bool Rational::negative() {
	return num < 0;
}
bool Rational::positive() {
	return num > 0;
}
bool operator==(Rational lhs, const Rational& rhs) {
	lhs -= rhs;
	return lhs.zero();
}
bool operator>(Rational lhs, const Rational& rhs) {
	lhs -= rhs;
	return lhs.positive();
}
bool operator<(Rational lhs, const Rational& rhs) {
	lhs -= rhs;
	return lhs.negative();
}
bool operator>=(Rational lhs, const Rational& rhs) {
	lhs -= rhs;
	return lhs.positive() || lhs.zero();
}
bool operator<=(Rational lhs, const Rational& rhs) {
	lhs -= rhs;
	return lhs.zero() || lhs.negative();
}
bool operator!=(Rational lhs, const Rational& rhs) {
	lhs -= rhs;
	return !(lhs.zero());
}









