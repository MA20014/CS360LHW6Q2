// HugeInt.h
#ifndef HUGEINT_H
#define HUGEINT_H

#include <array>
#include <iostream>
#include <string>

class HugeInt {
    friend std::ostream &operator<<(std::ostream &, const HugeInt &);

public:
    static const int digits = 30; // maximum digits in a HugeInt
    HugeInt(long = 0);            // conversion/default constructor
    HugeInt(const std::string &); // conversion constructor

    // addition operator overloads
    HugeInt operator+(const HugeInt &) const;
    HugeInt operator+(int) const;
    HugeInt operator+(const std::string &) const;

    // subtraction operator overloads
    HugeInt operator-(const HugeInt &) const;
    HugeInt operator-(int) const;
    HugeInt operator-(const std::string &) const;

    // multiplication operator overloads
    HugeInt operator*(const HugeInt &) const;
    HugeInt operator*(int) const;
    HugeInt operator*(const std::string &) const;

    // division operator overloads
    HugeInt operator/(const HugeInt &) const;
    HugeInt operator/(int) const;
    HugeInt operator/(const std::string &) const;

    // relational and equality operator overloads
    bool operator==(const HugeInt &) const;
    bool operator==(int) const;
    bool operator==(const std::string &) const;
    bool operator!=(const HugeInt &) const;
    bool operator!=(int) const;
    bool operator!=(const std::string &) const;
    bool operator<(const HugeInt &) const;
    bool operator<(int) const;
    bool operator<(const std::string &) const;
    bool operator>(const HugeInt &) const;
    bool operator>(int) const;
    bool operator>(const std::string &) const;
    bool operator<=(const HugeInt &) const;
    bool operator<=(int) const;
    bool operator<=(const std::string &) const;
    bool operator>=(const HugeInt &) const;
    bool operator>=(int) const;
    bool operator>=(const std::string &) const;

private:
    std::array<short, digits> integer;

    // Helper functions
    HugeInt abs() const; // Returns the absolute value of the HugeInt
    bool isZero() const; // Checks if the HugeInt is zero
};

#endif // HUGEINT_H

