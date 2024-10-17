cmake_minimum_required(VERSION 3.22)
project(bignum_benchmark)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()
include( ExternalProject )

set( boost_URL "http://sourceforge.net/projects/boost/files/boost/1.86.0/boost_1_86_0.tar.bz2" )
set( boost_SHA1 "fd0d26a7d5eadf454896942124544120e3b7a38f" )
set( boost_INSTALL ${CMAKE_CURRENT_BINARY_DIR}/third_party/boost )
set( boost_INCLUDE_DIR ${boost_INSTALL}/include )
set( boost_LIB_DIR ${boost_INSTALL}/lib )

ExternalProject_Add( external_boost
        PREFIX boost
        URL ${boost_URL}
        URL_HASH SHA1=${boost_SHA1}
        BUILD_IN_SOURCE 1
        CONFIGURE_COMMAND ./bootstrap.sh
            --with-libraries=system
            --prefix=<INSTALL_DIR>
        BUILD_COMMAND
        ./b2 install link=static variant=release threading=multi runtime-link=static
        INSTALL_COMMAND ""
        INSTALL_DIR ${boost_INSTALL} )

set( boost_LIBRARY_SUFFIX .a )

add_executable(bignum_benchmark)
add_dependencies(bignum_benchmark external_boost)
target_sources(bignum_benchmark PRIVATE
	main.cpp
)
target_include_directories(bignum_benchmark PRIVATE SYSTEM
   ${CMAKE_CURRENT_SOURCE_DIR}/libs/catch2/include
   ${boost_INCLUDE_DIR}
   /opt/local/include
)
target_link_libraries(bignum_benchmark PRIVATE
	/opt/local/lib/libmpfr.a
	/opt/local/lib/libgmp.a
)
