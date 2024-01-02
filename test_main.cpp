#include <iostream>
#include <cassert>
#include "main.cpp"


void common();
void leadingzeros();
void negative();
void spaced();
void bignumber();
void zero();
void allzeros();
void minuszero();
void empty();
void nonnumeric();


int main() {
    common();
    leadingzeros();
    negative();
    spaced();
    bignumber();
    zero();
    allzeros();
    minuszero();
    empty();
    nonnumeric();
    std::cout << "All test cases passed!" << std::endl;
    return 0;
}


void common() {
    assert(to4("123") == "1323");
}

void leadingzeros() {
    assert(to4("000123") == "1323");
}

void negative() {
    assert(to4("-123") == "-1323");
}

void spaced() {
    assert(to4("  123  ") == "1323");
}

void bignumber() {
    assert(to4("123456789123456789123456789") == "12120132333133023203230121331330001011330111");
}

void zero() {
    assert(to4("0") == "0");
}

void allzeros() {
    assert(to4("00000") == "0");
}

void minuszero() {
    assert(to4("-0") == "0");
}

void empty() {
    assert(to4("") == "Incorrect input, giving up.");
}

void nonnumeric() {
    assert(to4("abc") == "Incorrect input, giving up.");
}
