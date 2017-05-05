#ifndef _MILLER_RABIN_H_
#define _MILLER_RABIN_H_

#include <cstdlib>

static const int DEFAULT_ACCURACY = 5;

size_t pow_mod(size_t a, size_t x, size_t n);
bool is_prime(size_t n, int k = DEFAULT_ACCURACY);
#endif // _MILLER_RABIN_H_
