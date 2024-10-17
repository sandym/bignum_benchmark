#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/mpfr.hpp>

template<class T>
inline bool precisionIsGoodEnough( T a,
                                   std::type_identity_t<T> b,
                                   std::type_identity_t<T> prec )
{
	using namespace std;
	return abs( a - b ) < prec;
}

template<class T>
T computePi()
{
	// Tailor series
	// π/4 = 1 – 1/3 + 1/5 – 1/7 + ...

	T previous = 0;
	T pi_4 = 1;
	T i = 3;
	T m = -1;

	while ( not precisionIsGoodEnough(pi_4, previous, 0.0001) )
	{
		previous = pi_4;
		pi_4 = pi_4 + (m * (1 / i));
		m = -m;
		i += 2;
	}
	return pi_4 * 4;
}

TEST_CASE("computePi") {

	using namespace boost::multiprecision;

	std::cout << "c++ - double =           " << std::setprecision(50) << computePi<double>() << std::endl;
	std::cout << "c++ - long double =      " << std::setprecision(50) << computePi<long double>() << std::endl;
	std::cout << "c++ - cpp_dec_float_50 = " << std::setprecision(50) << computePi<cpp_dec_float_50>() << std::endl;
	std::cout << "c++ - mpfr_float_50 =    " << std::setprecision(50) << computePi<mpfr_float_50>() << std::endl;

    BENCHMARK("c++ - double") {
		return computePi<double>();
	};
    BENCHMARK("c++ - long double") {
		return computePi<long double>();
	};
	 BENCHMARK("c++ - cpp_dec_float_50") {
	 	return computePi<cpp_dec_float_50>();
	 };
	BENCHMARK("c++ - mpfr_float_50") {
		return computePi<mpfr_float_50>();
	};
}
