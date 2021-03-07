#include <pybind11/pybind11.h>
#include <pybind11/stl.h>


#include "fault_injection_messages_api.h"

namespace py = pybind11;
using pybind11::literals::operator""_a;

PYBIND11_MODULE(fault_injection_messages,m){
    py::class_<InjectionConfiguration>(m, "InjectionConfiguration");

    m.def("get_InjectionConfiguration", &get_InjectionConfiguration,
          py::arg("logging"),
          py::arg("register_injection_actions"),
          py::arg("memory_injection_actions"));

    m.def("encode_InjectionConfiguration", &encode_InjectionConfiguration,
          py::arg("configuration"));

    m.def("decode_InjectionConfiguration", &decode_InjectionConfiguration,
          py::arg("bytes_to_decode"));
}