#include "Rational.hpp"
#include "doctest.h"

TEST_CASE("Rational class tests") {

    SUBCASE("Test default constructor") {
        Rational r;
        REQUIRE(r.numer() == 0);
        REQUIRE(r.denomer() == 1);
    }

    SUBCASE("Test constructor with arguments") {
        Rational r(3, 4);
        REQUIRE(r.numer() == 3);
        REQUIRE(r.denomer() == 4);
    }

    SUBCASE("Test assignment operator") {
        Rational r1(2, 5);
        Rational r2;
        r2 = r1;
        REQUIRE(r2.num() == r1.num());
        REQUIRE(r2.denomer() == r1.denomer());
    }

    SUBCASE("Test arithmetic operators") {
        Rational r1(1, 3), r2(2, 5);
        Rational r3 = r1 + r2;
        REQUIRE(r3.num() == 11);
        REQUIRE(r3.denomer() == 15);
        Rational r4 = r1 - r2;
        REQUIRE(r4.num() == -1);
        REQUIRE(r4.denomer() == 15);
        Rational r5 = r1 * r2;
        REQUIRE(r5.num() == 2);
        REQUIRE(r5.denomer() == 15);
        Rational r6 = r1 / r2;
        REQUIRE(r6.num() == 5);
        REQUIRE(r6.denomer() == 6);
    }

    SUBCASE("Test comparison operators") {
        Rational r1(1, 3), r2(2, 5), r3(3, 5);
        REQUIRE(r1 < r2);
        REQUIRE(r1 <= r3);
        REQUIRE(r2 > r1);
        REQUIRE(r3 >= r1);
        REQUIRE(r1 == Rational(1, 3));
        REQUIRE(r2 != r3);
    }

    SUBCASE("Test stream operators") {
        Rational r(3, 4);
        std::stringstream ss;
        ss << r;
        REQUIRE(ss.str() == "3/4");
        Rational r2;
        ss >> r2;
        REQUIRE(r2.num() == 3);
        REQUIRE(r2.denomer() == 4);
    }
}
