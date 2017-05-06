/*
 * The Miller-Rabin primality test
 * Arbitrary Precision Version
 *
 * Written by Charles Liu 5/5/2017
 *
 * The code is producing a random prime number of a given number of bits:
 * INPUT:
 * 	Number of Bits
 * OUTPUT:
 * 	"primes.txt" // only produce one number
 */
#include "miller-rabin.h"
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/random.hpp>
#include <fstream>
#include <iostream>

int main() {
    using namespace boost::multiprecision;
    using namespace boost::random;
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ofstream;

    unsigned number_of_bit;
    cout << "Please input the bits of the number you want to generate: ";
    cin >> number_of_bit;
    cout << "We are testing " << number_of_bit << " bits numbers..." << endl;
    //
    // Generate integers in a given range using uniform_int,
    // the underlying generator is invoked multiple times
    // to generate enough bits:
    //
    mt19937 mt(time(0));
    uniform_int_distribution<uint1024_t> ui(
        (uint1024_t(1) << number_of_bit), uint1024_t(1) << (number_of_bit + 1));
    //
    // Generate the numbers:
    //
    int i = 0;
    while (true) {
        uint1024_t n = ui(mt);
        cout << "testing no. " << i++ << " number." << endl;
        if (is_prime(n)) {
            ofstream of("primes.txt");
            of << n << endl;
            of.close();
            break;
        }
    }
    return 0;
}
