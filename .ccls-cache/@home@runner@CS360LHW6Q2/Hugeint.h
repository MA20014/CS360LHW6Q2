#ifndef HUGEINT_H
#define HUGEINT_H

#include <array>
#include <iostream>
#include <string>

class HugeInt {
    friend std::ostream &operator<<(std::ostream &, const HugeInt &);

public:
    static const int digits = 30; // maximum digits in a HugeInt

    HugeInt(long = 0);                      // conversion/default constructor
    HugeInt(const std::string &);           // conversion constructor

    HugeInt operator+(const HugeInt &) const;     // addition operator; HugeInt + HugeInt
    HugeInt operator+(int) const;                  // addition operator; HugeInt + int
    HugeInt operator+(const std::string &) const;  // addition operator; HugeInt + string

    HugeInt operator*(const HugeInt &) const;     // multiplication operator; HugeInt * HugeInt
    HugeInt operator*(int) const;                 // multiplication operator; HugeInt * int
    HugeInt operator*(const std::string &) const; // multiplication operator; HugeInt * string

    HugeInt operator/(const HugeInt &) const;     // division operator; HugeInt / HugeInt
    HugeInt operator/(int) const;                 // division operator; HugeInt / int
    HugeInt operator/(const std::string &) const; // division operator; HugeInt / string

    bool operator==(const HugeInt &) const;  // equality operator; HugeInt == HugeInt
    bool operator!=(const HugeInt &) const;  // inequality operator; HugeInt != HugeInt
    bool operator<(const HugeInt &) const;   // less than operator; HugeInt < HugeInt
    bool operator<=(const HugeInt &) const;  // less than or equal to operator; HugeInt <= HugeInt
    bool operator>(const HugeInt &) const;   // greater than operator; HugeInt > HugeInt
    bool operator>=(const HugeInt &) const;  // greater than or equal to operator; HugeInt >= HugeInt

private:
    std::array<short, digits> integer;
};

#endif
