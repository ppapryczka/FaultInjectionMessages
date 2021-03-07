cmake_minimum_required(VERSION 3.17)
project(FaultInjectionMessage VERSION 1.0 DESCRIPTION "Messages represent in ASN.1 for STM32 fault injection.")
set(CMAKE_CXX_STANDARD 17)

add_executable(FaultInjectionMessage
        main.cpp
        acn.c
        asn1crt.h asn1crt.c
        fault_injection_messages.h fault_injection_messages.c
        real.c
        fault_injection_messages_api.h fault_injection_messages_api.cpp python_wrapper.cpp)

add_subdirectory(pybind11)

pybind11_add_module(fault_injection_messages
        python_wrapper.cpp
        acn.c
        asn1crt.h asn1crt.c
        fault_injection_messages.h fault_injection_messages.c
        real.c
        fault_injection_messages_api.h fault_injection_messages_api.cpp)

# EXAMPLE_VERSION_INFO is defined by setup.py and passed into the C++ code as a
# define (VERSION_INFO) here.
target_compile_definitions(fault_injection_messages PRIVATE VERSION_INFO=${EXAMPLE_VERSION_INFO})