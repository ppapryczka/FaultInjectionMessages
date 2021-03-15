#include <pybind11/pybind11.h>
#include <pybind11/stl.h>


#include "fault_injection_messages_api.h"

namespace py = pybind11;
using pybind11::literals::operator""_a;

PYBIND11_MODULE(fault_injection_messages,m){

    // Injection Configuration

    py::class_<InjectionConfiguration>(m, "InjectionConfiguration");

    m.def("get_InjectionConfiguration", &get_InjectionConfiguration,
          py::arg("logging"),
          py::arg("register_injection_actions"),
          py::arg("memory_injection_actions"));

    m.def("encode_InjectionConfiguration", &encode_InjectionConfiguration,
          py::arg("configuration"));

    m.def("decode_InjectionConfiguration", &decode_InjectionConfiguration,
          py::arg("bytes_to_decode"));

    // Injection Action

    py::class_<InjectionAction>(m, "InjectionAction");

    m.def("get_RegisterInjectionAction", &get_RegisterInjectionAction,
          py::arg("injection_address"),
          py::arg("register_index"),
          py::arg("value_mask"),
          py::arg("omit_calls_number"),
          py::arg("mask_operation"),
          py::arg("injection_index"));

    m.def("get_MemoryInjectionAction", &get_MemoryInjectionAction,
          py::arg("injection_address"),
          py::arg("memory_address"),
          py::arg("value_mask"),
          py::arg("omit_calls_number"),
          py::arg("mask_operation"),
          py::arg("injection_index"));

    m.def("encode_InjectionAction", &encode_InjectionAction,
          py::arg("injection_action"));

    m.def("decode_InjectionAction", &decode_InjectionAction,
          py::arg("bytes_to_decode"));


    // Exchange status

    py::enum_<ExchangeStatusEnum>(m, "ExchangeStatusEnum")
            .value("waitingConf", ExchangeStatusEnum::waitingConf)
            .value("sendingActions", ExchangeStatusEnum::sendingActions)
            .value("actionsReceived", ExchangeStatusEnum::actionsReceived)
            .export_values();

    py::class_<ExchangeStatus>(m, "ExchangeStatus");

    m.def("get_ExchangeStatus", &get_ExchangeStatus,
          py::arg("exchange_status_enum"));

    m.def("encode_ExchangeStatus", &encode_ExchangeStatus,
          py::arg("exchange_status"));

    m.def("decode_ExchangeStatus", &decode_ExchangeStatus,
          py::arg("bytes_to_decode"));
}