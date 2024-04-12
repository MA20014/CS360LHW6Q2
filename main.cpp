#include <iostream>
#include "HugeInt.h"

using namespace std;

int main() {
    HugeInt n1(7654321);
    HugeInt n2(7891234);
    HugeInt n3("99999999999999999999999999999");
    HugeInt n4("1");
    HugeInt n5;

    cout << "n1 is " << n1 << "\nn2 is " << n2
         << "\nn3 is " << n3 << "\nn4 is " << n4
         << "\nn5 is " << n5 << "\n\n";

    // Addition
    n5 = n1 + n2;
    cout << n1 << " + " << n2 << " = " << n5 << "\n\n";

    // Addition with different types
    cout << n3 << " + " << n4 << "\n= " << (n3 + n4) << "\n\n";
    n5 = n1 + 9;
    cout << n1 << " + " << 9 << " = " << n5 << "\n\n";
    n5 = n2 + "10000";
    cout << n2 << " + " << "10000" << " = " << n5 << "\n\n";

  // Subtraction
   cout << n3 << " - " << n4 << "\n= " << (n3 - n4) << "\n\n";
  
    // Multiplication
    HugeInt n6 = n1 * n2;
    cout << n1 << " * " << n2 << " = " << n6 << "\n\n";

    // Multiplication with different types
    n6 = n1 * 2;
    cout << n1 << " * " << 2 << " = " << n6 << "\n\n";
    n6 = n2 * "2";
    cout << n2 << " * " << "2" << " = " << n6 << "\n\n";

    // Division
    HugeInt n7 = n3 / n4;
    cout << n3 << " / " << n4 << " = " << n7 << "\n\n";

    // Division with different types
    n7 = n1 / 3;
    cout << n1 << " / " << 3 << " = " << n7 << "\n\n";
    n7 = n2 / "10";
    cout << n2 << " / " << "10" << " = " << n7 << "\n\n";

    // Relational and equality operators
    cout << n1 << " == " << n2 << " is " << boolalpha << (n1 == n2) << "\n\n";
    cout << n1 << " != " << n2 << " is " << boolalpha << (n1 != n2) << "\n\n";
    cout << n1 << " < " << n2 << " is " << boolalpha << (n1 < n2) << "\n\n";
    cout << n1 << " <= " << n2 << " is " << boolalpha << (n1 <= n2) << "\n\n";
    cout << n1 << " > " << n2 << " is " << boolalpha << (n1 > n2) << "\n\n";
    cout << n1 << " >= " << n2 << " is " << boolalpha << (n1 >= n2) << "\n\n";

    return 0;
}
