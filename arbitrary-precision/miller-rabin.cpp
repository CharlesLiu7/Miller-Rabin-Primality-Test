/*
 * The Miller-Rabin primality test
 * Arbitrary Precision Version
 *
 * Written by Charles Liu 5/5/2017
 *
 * NOTE:
 *	The code uses modular exponentiation by repeated squaring, the running
 *time of
 *	this algorithm is O(k log^3 n)
 *
 * 	The code has big room for improvements, but it does work as advertised.
 */

#include "miller-rabin.h"
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/random.hpp>
#include <iostream>
#include <iterator>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::iterator;
using namespace boost::multiprecision;
using namespace boost::random;

/*
 * random number engine
 */
static mt19937 mt(time(0));

/*
 * Fast calculation of `a^x mod n´ by using right-to-left binary modular
 * exponentiation.
 *
 * See http://en.wikipedia.org/wiki/Modular_exponentiation
 */
uint1024_t pow_mod(uint1024_t a, uint1024_t x, uint1024_t n) {
    /*
     * Note that this code is sensitive to overflowing for testing of large
     * prime numbers.  The `a*r´ and `a*a´ operations can overflow.  One easy
     * way of solving this is to use 128-bit precision for calculating a*b % n,
     * since the mod operator should always get us back to 64bits again.
     *
     * You can either use GCC's built-in __int128_t or use
     *
     * typedef unsigned int uint128_t __attribute__((mode(TI)));
     *
     * to create a 128-bit datatype.
     */
    uint1024_t r = 1;
    while (x) {
        if ((x & 1) == 1)
            r = a * r % n;
        a = a * a % n;
        x >>= 1;
    }
    return r;
}

/*
 * The Miller-Rabin probabilistic primality test.
 *
 * Returns true if ``n´´ is PROBABLY prime, false if it's composite.
 * The parameter ``k´´ is the accuracy.
 *
 * The running time should be somewhere around O(k log^3 n).
 *
 */
bool is_prime(uint1024_t n, int k) {
    // Must have ODD n greater than THREE
    if (n == 2 || n == 3)
        return true;
    if (n <= 1 || !(n & 1))
        return false;

    // Write n-1 as d*2^s by factoring powers of 2 from n-1
    int s = 0;
    uint1024_t d = n - 1;
    for (; !(d & 1); ++s, d >>= 1)
        ; // loop

    // ------Speed up section begin------
    // with k=13 and accuracy=100%
    // if n<3,317,044,064,679,887,385,961,981 it is enough to test
    // a=2,3,5,7,11,13,17,19,23,29,31,37,41
    // vector<unsigned> list_a = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,
    // 41};
    // if (n < uint1024_t("3317044064679887385961981")) {
    // for (auto i = list_a.cbegin(); i != list_a.cend(); ++i) {
    // uint1024_t a = *i;
    // uint1024_t reminder = pow_mod(a, d, n);
    // if (reminder == 1 | reminder == (n - 1))
    // continue;
    // for (int r = 1; r <= s - 1; ++r) {
    // reminder = pow_mod(reminder, 2, n);
    // if (reminder == 1)
    // return false; // n is not a prime, and a is a witness
    // if (reminder == n - 1)
    // goto NEXT_WITNESS_SPEEDUP;
    // }
    // return false;
    // NEXT_WITNESS_SPEEDUP:
    // continue;
    // }
    // }
    // ------Speed up section end------
    // Here, we CANNOT set it static
    uniform_int_distribution<uint1024_t> u(uint1024_t(2), n - 2);
    for (int i = 0; i < k; ++i) {
        uint1024_t a = u(mt);
        uint1024_t reminder = pow_mod(a, d, n);
        if (reminder == 1 | reminder == (n - 1))
            continue;
        for (int r = 1; r <= s - 1; ++r) {
            reminder = pow_mod(reminder, 2, n);
            if (reminder == 1)
                return false; // n is not a prime, and a is a witness
            if (reminder == n - 1)
                goto NEXT_WITNESS;
        }
        return false;
    NEXT_WITNESS:
        continue;
    }

    return true; // n is *probably* prime
}
