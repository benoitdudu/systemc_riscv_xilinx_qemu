
project (test_xilinx_qemu CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INSTALL_RPATH $ORIGIN)

set (LIBSYSTEMCTLM_SOC_DIR "../libsystemctlm-soc")

set (SRC
    sc_main.cpp
)
set (SYSTEMC_INC_DIR ../build/install/systemc/include)
get_filename_component (SYSTEMC_LIB_DIR ../build/install/systemc/lib REALPATH)
set (SYSTEMC_SO ${SYSTEMC_LIB_DIR}/libsystemc.so)
add_executable (test ${SRC})

target_include_directories(test
  PUBLIC
  ${SYSTEMC_INC_DIR})

target_link_libraries(test
    ${SYSTEMC_SO}
)

install (TARGETS test RUNTIME DESTINATION bin)

install(DIRECTORY ${SYSTEMC_LIB_DIR}/
    DESTINATION bin
    PATTERN "cmake" EXCLUDE
)