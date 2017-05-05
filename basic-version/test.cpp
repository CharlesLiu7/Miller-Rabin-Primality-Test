/*
 * The Miller-Rabin primality test
 *
 * This is a code for testing the algorithm writen in miller-rabin.cpp
 *
 * Written by Huiqi Liu 5/5/2017
 */

#include "miller-rabin.h"
#include <iostream>
using namespace std;

/*
 * count how many numbers in [1, n] are prime numbers
 */
static int range_test(int n) {
    int r = 0, m = 2;
    while (m < n)
        if (is_prime(m++))
            ++r;
    return r;
}

int main() {
    cout << "This is a test for calculating number of primes by using the "
            "Miller-Rabin primality test.\n"
            "\n"
            "Note that since this is a probabilistic algorithm, each run can\n"
            "produce different results.  That is why you might see incorrect\n"
            "results below, from time to time.\n"
            "\n"
            "Written by Huiqi Liu 5/5/2017\n"
            "\n"
         << endl;

    // this is a strong pseudo prime number in 10^16
    size_t strong_pseudo_prime = 46856248255981;
    cout << strong_pseudo_prime
         << " is a strong pseudo prime, so here we test it: "
         << is_prime(strong_pseudo_prime) << endl
         << endl;

    int expected[] = {0, 4, 25, 168, 1229, 9592, 78498, 664579};

    for (int n = 1, e = 0; n <= 10000000; n *= 10, ++e) {
        int primes = range_test(n);
        cout << "There are " << primes << " primes less than " << n << endl;

        if (primes != expected[e])
            cout << " --- FAIL, expecteded " << expected[e] << endl;
    }
    return 0;
}
