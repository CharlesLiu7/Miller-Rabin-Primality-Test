#include "miller-rabin.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>

using namespace std;

static default_random_engine e(time(0));

size_t pow_mod(size_t a, size_t x, size_t n) {
    size_t r = 1;
    while (x) {
        if ((x & 1) == 1)
            r = a * r % n;
        a = a * a % n;
        x >>= 1;
    }
    return r;
}

bool is_prime(size_t n, int k) {
    // Must have ODD n greater than THREE
    if (n == 2 || n == 3)
        return true;
    if (n <= 1 || !(n & 1))
        return false;

    // Write n-1 as d*2^s by factoring powers of 2 from n-1
    int s = 0;
    size_t d = n - 1;
    for (; !(d & 1); ++s, d >>= 1)
        ; // loop
    uniform_int_distribution<size_t> u(2, n - 2);
    for (int i = 0; i < k; ++i) {
		size_t a = u(e);
        size_t reminder = pow_mod(a, d, n);
        if (reminder == 1 | reminder == (n - 1))
            continue;
        for (int r = 1; r <= s - 1; ++r) {
            reminder = pow_mod(reminder, 2, n);
            if (reminder == 1)
                return false;
            if (reminder == n - 1)
                goto NEXT_WITNESS;
        }
        return false;
    NEXT_WITNESS:
        continue;
    }
    return true;
}
