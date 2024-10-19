
find_path(GMP_INCLUDES
	NAMES gmp.h
	PATHS
		/usr/include
		/usr/local/include
		/opt/local/include
)

find_library(
	GMP_LIBRARIES gmp
	PATHS
		/usr/lib64
		/usr/lib
		/usr/local/lib
		/opt/local/lib
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(GMP
	DEFAULT_MSG
    GMP_INCLUDES GMP_LIBRARIES)

mark_as_advanced(GMP_INCLUDES GMP_LIBRARIES)

add_library(GMP INTERFACE)
target_include_directories(GMP INTERFACE ${GMP_INCLUDES})
target_link_libraries(GMP INTERFACE ${GMP_LIBRARIES})
