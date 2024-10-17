
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
c++ - double                                   100             2      2.011 ms
                                        9.99661 us    9.98887 us    10.0056 us
                                        42.7888 ns    36.4479 ns    51.5103 ns

c++ - long double                              100             2      2.002 ms
                                         10.023 us    10.0062 us     10.058 us
                                        119.067 ns    59.0551 ns    202.835 ns

c++ - cpp_dec_float_50                         100             1    513.649 ms
                                        5.12636 ms    5.11923 ms    5.13871 ms
                                        46.7369 us    31.5427 us    75.1531 us

c++ - mpfr_float_50                            100             1    224.598 ms
                                        2.40176 ms    2.39496 ms    2.41154 ms
                                        41.3239 us    30.9517 us    53.0149 us


===============================================================================
test cases: 1 | 1 passed
assertions: - none -
```

`mpfr_float_50` is twice the speed of `cpp_dec_float_50`.
