
# The benchmark

This benchmark compute the value of π up to `0.0001` using a
Tailor serie. It does it with `double`, `long double`,
`cpp_dec_float_50` and `mpfr_float_50`.

# The results

```
> ./bignum_benchmark
c++ - double =           3.1417926135957907618490025924984365701675415039062
c++ - long double =      3.1417926135957907618490025924984365701675415039062
c++ - cpp_dec_float_50 = 3.1417926135957928384026393958794601181977798588306
c++ - mpfr_float_50 =    3.1417926135957928384026393958794601181977798588303

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
bignum_benchmark is a Catch v2.13.8 host application.
Run with -? for options

-------------------------------------------------------------------------------
computePi
-------------------------------------------------------------------------------
/Users/sandy/projets/bignum_benchmark/main.cpp:37
...............................................................................

benchmark name                       samples       iterations    estimated
                                     mean          low mean      high mean
                                     std dev       low std dev   high std dev
-------------------------------------------------------------------------------
c++ - double                                   100             2     1.9966 ms
                                         9.9543 us    9.95097 us    9.95889 us
                                        19.6994 ns    14.8916 ns    32.4928 ns

c++ - long double                              100             2     1.9982 ms
                                        10.0478 us     9.9641 us    10.4541 us
                                        809.913 ns    37.6539 ns    1.92958 us

c++ - cpp_dec_float_50                         100             1    399.947 ms
                                        3.99811 ms    3.99505 ms     4.0031 ms
                                        19.6161 us    13.5582 us    29.0831 us

c++ - mpfr_float_50                            100             1    202.279 ms
                                        2.02991 ms    2.02584 ms    2.03758 ms
                                        27.5354 us    15.7219 us    41.0004 us

===============================================================================
test cases: 1 | 1 passed
assertions: - none -
```

`mpfr_float_50` is twice the speed of `cpp_dec_float_50`.
