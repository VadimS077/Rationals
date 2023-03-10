// Rational.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once


#include <iosfwd>



class Rational {
private:
	int num;
	int denom;
	static const char sep = '/';
	


public:
	Rational();
	Rational(int n);
	Rational(int n, int d);
	int nod(int num, int denom);
	Rational& reducing();
	bool zero();
	bool negative();
	bool positive();
	int numer();
	int denomer();
	
public:
    Rational& operator=(const Rational& rhs);
    Rational& operator+=(const Rational& rhs);
    Rational& operator-=(const Rational& rhs);
    Rational& operator*=(const Rational& rhs);
    Rational& operator/=(const Rational& rhs);
	std::ostream& writeto(std::ostream& ostrm) const;
	std::istream& readfrom(std::istream& istrm);
	Rational& operator++();
	Rational operator++(int);
	Rational& operator--();
	Rational operator--(int);
	Rational operator+();
	Rational operator-();
	


	

	
	
};
bool operator==(Rational lhs, const Rational& rhs);
bool operator>(Rational lhs, const Rational& rhs);
bool operator<(Rational lhs, const Rational& rhs);
bool operator!=(const Rational& lhs, const Rational& rhs);
bool operator<=(const Rational& lhs, const Rational& rhs);
bool operator>=(const Rational& lhs, const Rational& rhs);
Rational operator+(Rational lhs, const Rational& rhs);
Rational operator-(Rational lhs, const Rational& rhs);
Rational operator*(Rational lhs, const Rational& rhs);
Rational operator/(Rational lhs, const Rational& rhs);
std::istream& operator>>(std::istream& istrm, Rational& rat);
std::ostream& operator<<(std::ostream& ostrm, const Rational& rat);
