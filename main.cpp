#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include <catch.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/mpfr.hpp>
#ifdef __x86_64__
#include <boost/multiprecision/float128.hpp>
#endif

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

	const T kOne = 1;
	const T kTwo = 2;
	const T kPrec = 0.0001;

	while ( not precisionIsGoodEnough(pi_4, previous, kPrec) )
	{
		previous = pi_4;
		pi_4 = pi_4 + (m * (kOne / i));
		m = -m;
		i += kTwo;
	}
	return pi_4 * 4;
}

TEST_CASE("computePi") {

	using namespace boost::multiprecision;

	std::cout << "c++ - double =           " << std::setprecision(50) << computePi<double>() << std::endl;
	std::cout << "c++ - long double =      " << std::setprecision(50) << computePi<long double>() << std::endl;
	std::cout << "c++ - cpp_dec_float_50 = " << std::setprecision(50) << computePi<cpp_dec_float_50>() << std::endl;
	std::cout << "c++ - mpfr_float_50 =    " << std::setprecision(50) << computePi<mpfr_float_50>() << std::endl;
#ifdef __x86_64__
	std::cout << "c++ - float128      =    " << std::setprecision(50) << computePi<float128>() << std::endl;
#endif

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
#ifdef __x86_64__
	BENCHMARK("c++ - float128") {
		return computePi<float128>();
	};
#endif
}
