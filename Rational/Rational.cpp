﻿// Rational.cpp: определяет точку входа для приложения.
//

#include "Rational.hpp"
#include <iostream>
#include <cassert>




	
Rational::Rational() {
	num = 0;
	denom = 1;
}
Rational::Rational(int n) {
	num = n;
	denom = 1;
}
Rational::Rational(int n, int d) {
	assert(d != 0);
	

	num = n;
	denom = d;
	
	
	
	
}
int Rational::numer(){
	return num;
	
}
int Rational::denomer() {
	return denom;
}


int Rational::nod(int n, int d) {
	assert(d != 0);
	while (d != 0) {
		int temp = d;
		d = n % d;
		n = temp;
	}
	return std::abs(n);
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
std::ostream& operator<<(std::ostream& ostrm, const Rational& rat) {
	return rat.writeto(ostrm);
}
std::ostream& Rational::writeto(std::ostream& ostrm) const {
	ostrm << num << sep << denom;
	assert(denom != 0);
	
	return ostrm;
	

}
std::istream& operator>>(std::istream& istrm, Rational& rat) {
	return rat.readfrom(istrm);
}
std::istream& Rational::readfrom(std::istream& istrm) {
	char sep = 0;
	int numer = 0;
	int denomer = 1;
	istrm >> numer >> sep >> denomer;
	assert(denomer != 0);
	if (istrm.good()) {
		if (sep == Rational::sep) {
			num = numer;
			denom = denomer;

		}
		else {
			istrm.setstate(std::ios_base::failbit);
		}

	}
	return istrm;
}



	
	







