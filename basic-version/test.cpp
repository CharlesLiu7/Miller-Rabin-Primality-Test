#include "miller-rabin.h"
#include <iostream>
using namespace std;

static int range_test(int n) {
    int r = 0, m = 2;

    while (m < n)
        if (is_prime(m++))
            ++r;

    return r;
}

int main() {
    // this is a strong pseudo prime number in 10^16
    size_t strong_pseudo_prime = 46856248255981;
    cout << strong_pseudo_prime << " test: " << is_prime(strong_pseudo_prime)
         << endl;

    int expected[] = {0, 4, 25, 168, 1229, 9592, 78498, 664579};

    for (int n = 1, e = 0; n <= 10000000; n *= 10, ++e) {
        int primes = range_test(n);
        cout << "There are " << primes << " primes less than " << n << endl;

        if (primes != expected[e])
            cout << " --- FAIL, expecteded " << expected[e] << endl;
    }
}
