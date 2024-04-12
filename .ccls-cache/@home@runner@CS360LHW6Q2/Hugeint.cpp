#include <cctype>
#include "HugeInt.h"

using namespace std;

HugeInt::HugeInt(long value) {
    for (short &element : integer)
        element = 0;

    for (size_t j = digits - 1; value != 0 && j >= 0; j--) {
        integer[j] = value % 10;
        value /= 10;
    }
}

HugeInt::HugeInt(const string &number) {
    for (short &element : integer)
        element = 0;

    size_t length = number.size();
    for (size_t j = digits - length, k = 0; j < digits; ++j, ++k)
        if (isdigit(number[k]))
            integer[j] = number[k] - '0';
}

HugeInt HugeInt::operator+(const HugeInt &op2) const {
    HugeInt temp;
    int carry = 0;
    for (int i = digits - 1; i >= 0; i--) {
        temp.integer[i] = integer[i] + op2.integer[i] + carry;
        if (temp.integer[i] > 9) {
            temp.integer[i] %= 10;
            carry = 1;
        } else
            carry = 0;
    }
    return temp;
}

HugeInt HugeInt::operator+(int op2) const {
    return *this + HugeInt(op2);
}

HugeInt HugeInt::operator+(const string &op2) const {
    return *this + HugeInt(op2);
}

HugeInt HugeInt::operator*(const HugeInt &op2) const {
    HugeInt copy(*this), res(0);

    for (int i = 0; i < digits; i++) {
        int num = op2.integer[i];
        if (num > 0) {
            HugeInt tmp(copy);

            int carry = 0;
            for (int j = digits - 1; j >= 0; j--) {
                tmp.integer[j] = tmp.integer[j] * num + carry;
                carry = tmp.integer[j] / 10;
                tmp.integer[j] %= 10;
            }

            for (int j = 0; j < i + 1; j++)
                tmp.integer[j] = tmp.integer[j + digits - 1 - i];
            for (int j = i + 1; j < digits; j++)
                tmp.integer[j] = 0;

            res = res + tmp;
        }
    }

    return res;
}

HugeInt HugeInt::operator*(int op2) const {
    return *this * HugeInt(op2);
}

HugeInt HugeInt::operator*(const string &op2) const {
    return *this * HugeInt(op2);
}

HugeInt HugeInt::operator/(const HugeInt &op2) const {
    if (*this == op2)
        return HugeInt(1);

    HugeInt tmp = op2, res;
    while (*this >= tmp) {
        res = res + 1;
        tmp = tmp + op2;
    }
    return res;
}

HugeInt HugeInt::operator/(int op2) const {
    return *this / HugeInt(op2);
}

HugeInt HugeInt::operator/(const string &op2) const {
    return *this / HugeInt(op2);
}

bool HugeInt::operator==(const HugeInt &op2) const {
    for (int i = digits - 1; i >= 0; i--)
        if (integer[i] != op2.integer[i])
            return false;
    return true;
}

bool HugeInt::operator!=(const HugeInt &op2) const {
    return !(*this == op2);
}

bool HugeInt::operator<(const HugeInt &op2) const {
    for (int i = 0; i < digits; i++) {
        if (integer[i] < op2.integer[i])
            return true;
        else if (integer[i] > op2.integer[i])
            return false;
    }
    return false;
}

bool HugeInt::operator<=(const HugeInt &op2) const {
    return *this == op2 || *this < op2;
}

bool HugeInt::operator>(const HugeInt &op2) const {
    return !(*this <= op2);
}

bool HugeInt::operator>=(const HugeInt &op2) const {
    return !(*this < op2);
}

std::ostream &operator<<(std::ostream &output, const HugeInt &num) {
    int i;
    for (i = 0; (i < HugeInt::digits) && (0 == num.integer[i]); ++i)
        ;
    if (i == HugeInt::digits)
        output << 0;
    else
        for (; i < HugeInt::digits; ++i)
            output << num.integer[i];
    return output;
}
