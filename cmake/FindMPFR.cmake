
find_path(MPFR_INCLUDES
	NAMES mpfr.h
	PATHS
		/usr/include
		/usr/local/include
		/opt/local/include
)

find_library(
	MPFR_LIBRARIES mpfr
	PATHS
		/usr/lib64
		/usr/lib
		/usr/local/lib
		/opt/local/lib
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(MPFR
	DEFAULT_MSG
    MPFR_INCLUDES MPFR_LIBRARIES)

mark_as_advanced(MPFR_INCLUDES MPFR_LIBRARIES)

add_library(MPFR INTERFACE)
target_include_directories(MPFR INTERFACE ${MPFR_INCLUDES})
target_link_libraries(MPFR INTERFACE ${MPFR_LIBRARIES})
