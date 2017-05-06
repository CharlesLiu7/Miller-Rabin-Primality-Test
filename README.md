# The Miller-Rabin Primality Test in C++

[Wiki/Miller–Rabin primality test](https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test)

> The Miller–Rabin primality test or Rabin–Miller primality test is a primality test: an algorithm which determines whether a given number is prime, similar to the Fermat primality test and the Solovay–Strassen primality test. Its original version, due to Gary L. Miller, is deterministic, but the determinism relies on the unproven Extended Riemann hypothesis; Michael O. Rabin modified it to obtain an unconditional probabilistic algorithm.

```
Compile Environment:
g++ 6.3.1
GNU make 4,2,1
boost 1.63.0
```
## Basic Version

By its probabilistic nature, it runs in O(k log3 n) time. But there is a chance for false positives;

- It can report that a number is prime while it is not. 
- False negatives are impossible, though. If it reports a number is composite, it is.

Here are a list of tricks we may used to improve the performance:

- FFT-based multiplication
- if n < 2,047, it is enough to test a = 2;
- if n < 1,373,653, it is enough to test a = 2 and 3;
- if n < 9,080,191, it is enough to test a = 31 and 73;
- if n < 25,326,001, it is enough to test a = 2, 3, and 5;
- if n < 3,215,031,751, it is enough to test a = 2, 3, 5, and 7;
- if n < 4,759,123,141, it is enough to test a = 2, 7, and 61;
- if n < 1,122,004,669,633, it is enough to test a = 2, 13, 23, and 1662803;
- if n < 2,152,302,898,747, it is enough to test a = 2, 3, 5, 7, and 11;
- if n < 3,474,749,660,383, it is enough to test a = 2, 3, 5, 7, 11, and 13;
- if n < 341,550,071,728,321, it is enough to test a = 2, 3, 5, 7, 11, 13, and 17.
- if n < 3,825,123,056,546,413,051, it is enough to test a = 2, 3, 5, 7, 11, 13, 17, 19, and 23.
- if n < 18,446,744,073,709,551,616 = 264, it is enough to test a = 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, and 37.
- if n < 318,665,857,834,031,151,167,461, it is enough to test a = 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, and 37.
- if n < 3,317,044,064,679,887,385,961,981, it is enough to test a = 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, and 41.

### compile

```
make
./test.out
```

### desired output

```
This is a test for calculating number of primes by using the Miller-Rabin primality test.

Note that since this is a probabilistic algorithm, each run can
produce different results.  That is why you might see incorrect
results below, from time to time.

Written by Charles Liu 5/5/2017


46856248255981 is a strong pseudo prime, so here we test it: 0

There are 0 primes less than 1
There are 4 primes less than 10
There are 25 primes less than 100
There are 168 primes less than 1000
There are 1229 primes less than 10000
There are 9592 primes less than 100000
There are 78498 primes less than 1000000
There are 664579 primes less than 10000000
```

## Arbitrary Version

I'm using [BOOST](http://www.boost.org/doc/libs/1_64_0/libs/multiprecision/doc/html/index.html) Library to process arbitrary precision numbers. And I use the `uint1024_t` type which is up to 144 bits unsigned integer, while the code is slow. `gmp_int` will be faster, but it only have 16 bits.

BOOST also has a built-in Template of [Miller_-Rabin Primality Test](http://www.boost.org/doc/libs/1_64_0/libs/multiprecision/doc/html/boost_multiprecision/tut/primetest.html).

### compile and usage
```
#compile
make
```
Here I have a basic test which is similar to the previous one.
```
./test.out
```

And we can produce a random prime number of a given number of bits:
```
# INPUT:
# 	Number of Bits
# OUTPUT:
# 	"primes.txt" // only produce one number
./generate.out
```

We can also test a number from a file whether it is a prime number:
```
# INPUT:
# 	"input.txt" //only accept one number
# OUTPUT:
# 	TRUE or FALSE
./primality.out
```

## Efficient codes

Ref: [wizykowski's code](https://github.com/wizykowski/miller-rabin)


