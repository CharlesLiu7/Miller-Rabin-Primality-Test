/*
 * The Miller-Rabin primality test
 * Arbitrary Precision Version
 *
 * Written by Charles Liu 5/5/2017
 *
 * The code is testing a number from input file whether it is a prime number:
 *
 * INPUT:
 * 	"input.txt" //only accept one number
 * OUTPUT:
 * 	TRUE or FALSE
 */

#include "miller-rabin.h"
#include <boost/multiprecision/cpp_int.hpp>
#include <fstream>
#include <iostream>
#include <string>

int main() {
    using namespace boost::multiprecision;
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ifstream;
    using std::string;

    ifstream fi("input.txt");
    if (!fi) {
        cout << "Error opening file.\n";
        return 1;
    }
    string n;
    getline(fi, n);

    cout << "the number which is testing now is " << n << endl;
    if (is_prime(uint1024_t(n))) {
        cout << "This is a prime (with default accuracy 5)" << endl;
    } else {
        cout << "This is not a prime!!!" << endl;
    }
    return 0;
}
