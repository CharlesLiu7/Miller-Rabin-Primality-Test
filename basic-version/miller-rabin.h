/*
 * The Miller-Rabin primality test
 *
 * Written by Huiqi Liu 5/5/2017
 */

#ifndef _MILLER_RABIN_H_
#define _MILLER_RABIN_H_

#include <cstdlib>

/*
 * Accuracy parameter `k´ of the Miller-Rabin algorithm.
 * The test declare n probably prime with a probability at most 4^(-k)
 */
static const int DEFAULT_ACCURACY = 5;

/*
 * Fast calculation of `a^x mod n´ by using right-to-left binary modular
 * exponentiation.
 *
 * See http://en.wikipedia.org/wiki/Modular_exponentiation
 */
size_t pow_mod(size_t a, size_t x, size_t n);
/*
 * The Miller-Rabin probabilistic primality test.
 *
 * Returns true if ``n´´ is PROBABLY prime, false if it's composite.
 * The parameter ``k´´ is the accuracy.
 *
 * The running time should be somewhere around O(k log^3 n).
 *
 */
bool is_prime(size_t n, int k = DEFAULT_ACCURACY);
#endif // _MILLER_RABIN_H_
