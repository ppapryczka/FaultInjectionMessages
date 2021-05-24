cmake_minimum_required(VERSION 3.17)
project(FaultInjectionMessage VERSION 1.0 DESCRIPTION "Messages represent in ASN.1 for STM32 fault injection.")
set(CMAKE_CXX_STANDARD 17)

# required to fetch dependencies
include(FetchContent)

# ----------------------------
# PYTHON LIBRARY - p2eb_python
# ----------------------------

# fetch pybind11 library
FetchContent_Declare(
        pybind11
        GIT_REPOSITORY https://github.com/pybind/pybind11.git
        GIT_TAG        v2.6.1)
FetchContent_MakeAvailable(pybind11)

pybind11_add_module(fault_injection_messages
        src/python_wrapper/python_wrapper.cpp
        # sources
        src/asn_files/acn.c
        src/asn_files/asn1crt.h
        src/asn_files/asn1crt.c
        src/asn_files/fault_injection_messages.h
        src/asn_files/fault_injection_messages.c
        src/asn_files/real.c
        src/api/exchange_status_asn_api.h
        src/api/exchange_status_asn_api.cpp
        src/api/injection_action_asn_api.cpp
        src/api/injection_action_asn_api.h
        src/api/injection_configuration_asn_api.cpp
        src/api/injection_configuration_asn_api.h
        src/api/log_asn_api.h
        src/api/log_asn_api.cpp)

# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(fault_injection_messages PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})


# --------------------------------------
# Tests - fault_injection_messages_tests
# --------------------------------------

# fetch Catch2 library
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v2.13.1)
FetchContent_MakeAvailable(Catch2)

# create executable
add_executable(fault_injection_messages_tests
        tests/main.cpp
        tests/test_injection_configuration_messages_api.cpp
        tests/test_injection_action_asn_api.cpp
        tests/test_exchange_status_asn_api.cpp
        tests/test_log_asn_api.cpp
        # sources
        src/asn_files/acn.c
        src/asn_files/asn1crt.h
        src/asn_files/asn1crt.c
        src/asn_files/fault_injection_messages.h
        src/asn_files/fault_injection_messages.c
        src/asn_files/real.c
        src/api/exchange_status_asn_api.h
        src/api/exchange_status_asn_api.cpp
        src/api/injection_action_asn_api.cpp
        src/api/injection_action_asn_api.h
        src/api/injection_configuration_asn_api.cpp
        src/api/injection_configuration_asn_api.h
        src/api/log_asn_api.h
        src/api/log_asn_api.cpp)

# link Catch2
target_link_libraries(fault_injection_messages_tests PRIVATE Catch2::Catch2)