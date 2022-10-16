cmake_minimum_required(VERSION 3.10)

project (test_xilinx_qemu CXX C)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INSTALL_RPATH $ORIGIN)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set (LIBSYSTEMCTLM_SOC_DIR "../libsystemctlm-soc")
set (LIBREMOTEPORT_DIR "${LIBSYSTEMCTLM_SOC_DIR}/libremote-port")

set(LIBREMOTEPORT_SRC
    ${LIBREMOTEPORT_DIR}/remote-port-proto.c
    ${LIBREMOTEPORT_DIR}/remote-port-sk.c
    ${LIBREMOTEPORT_DIR}/remote-port-tlm-ats.cc
    ${LIBREMOTEPORT_DIR}/remote-port-tlm-memory-master.cc
    ${LIBREMOTEPORT_DIR}/remote-port-tlm-memory-slave.cc
    ${LIBREMOTEPORT_DIR}/remote-port-tlm-pci-ep.cc
    ${LIBREMOTEPORT_DIR}/remote-port-tlm-wires.cc
    ${LIBREMOTEPORT_DIR}/remote-port-tlm.cc
    ${LIBREMOTEPORT_DIR}/remote-port-tlm.cc
    ${LIBREMOTEPORT_DIR}/safeio.c
)
set (SRC
    qemu_cosim.cpp
    sc_main.cpp
    target_systemc.cpp
    top.cpp
    ${LIBREMOTEPORT_SRC}
)
set (SYSTEMC_INC_DIR ../build/install/systemc/include)
get_filename_component (SYSTEMC_LIB_DIR ../build/install/systemc/lib REALPATH)
set (SYSTEMC_SO ${SYSTEMC_LIB_DIR}/libsystemc.so)

add_executable (test_qemu_cosim ${SRC})

target_include_directories(test_qemu_cosim
  PUBLIC
  ${SYSTEMC_INC_DIR}
  ${LIBSYSTEMCTLM_SOC_DIR}
  ${LIBREMOTEPORT_DIR}
)

target_link_libraries(test_qemu_cosim
    ${SYSTEMC_SO}
    Threads::Threads
)

install (TARGETS test_qemu_cosim RUNTIME DESTINATION bin)

install(DIRECTORY ${SYSTEMC_LIB_DIR}/
    DESTINATION bin
    PATTERN "cmake" EXCLUDE
)