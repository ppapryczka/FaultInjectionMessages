#include <pybind11/pybind11.h>
#include <pybind11/stl.h>


#include "../asn_files/fault_injection_messages.h"
#include "../api/injection_action_asn_api.h"
#include "../api/injection_configuration_asn_api.h"
#include "../api/exchange_status_asn_api.h"
#include "../api/log_asn_api.h"


namespace py = pybind11;
using pybind11::literals::operator""_a;

PYBIND11_MODULE(fault_injection_messages,m){
    // Mask Operation

    py::enum_<MaskOperationASN>(m, "MaskOperationASN")
            .value("orOperation", MaskOperationASN::orOperation)
            .value("setOperation", MaskOperationASN::setOperation)
            .value("xorOperation", MaskOperationASN::xorOperation)
            .export_values();

    // Injection Configuration

    py::class_<InjectionConfigurationASN>(m, "InjectionConfigurationASN");

    m.def("get_InjectionConfigurationASN", &get_InjectionConfigurationASN,
          py::arg("logging"),
          py::arg("register_injection_actions"),
          py::arg("memory_injection_actions"));

    m.def("encode_InjectionConfigurationASN", &encode_InjectionConfigurationASN,
          py::arg("configuration"));

    m.def("decode_InjectionConfigurationASN", &decode_InjectionConfigurationASN,
          py::arg("bytes_to_decode"));

    // Injection Action

    py::class_<InjectionActionASN>(m, "InjectionActionASN");

    m.def("get_RegisterInjectionActionASN", &get_RegisterInjectionActionASN,
          py::arg("injection_address"),
          py::arg("register_index"),
          py::arg("value_mask"),
          py::arg("omit_calls_number"),
          py::arg("mask_operation"),
          py::arg("injection_index"));

    m.def("get_MemoryInjectionActionASN", &get_MemoryInjectionActionASN,
          py::arg("injection_address"),
          py::arg("memory_address"),
          py::arg("value_mask"),
          py::arg("omit_calls_number"),
          py::arg("mask_operation"),
          py::arg("injection_index"));

    m.def("encode_InjectionActionASN", &encode_InjectionActionASN,
          py::arg("injection_action"));

    m.def("decode_InjectionActionASN", &decode_InjectionActionASN,
          py::arg("bytes_to_decode"));


    // Exchange status

    py::enum_<ExchangeStatusEnumASN>(m, "ExchangeStatusEnumASN")
            .value("waitingConf", ExchangeStatusEnumASN::waitingConf)
            .value("sendingActions", ExchangeStatusEnumASN::sendingActions)
            .value("actionsReceived", ExchangeStatusEnumASN::actionsReceived)
            .export_values();

    py::class_<ExchangeStatusASN>(m, "ExchangeStatusASN");

    m.def("get_ExchangeStatusASN", &get_ExchangeStatusASN,
          py::arg("exchange_status_enum"));

    m.def("encode_ExchangeStatusASN", &encode_ExchangeStatusASN,
          py::arg("exchange_status"));

    m.def("decode_ExchangeStatusASN", &decode_ExchangeStatusASN,
          py::arg("bytes_to_decode"));

    m.def("decode_state_and_check_if_is_expected", &decode_state_and_check_if_is_expected,
          py::arg("bytes_to_decode"),
          py::arg("expected_state"));

    // Log

    py::class_<LogASN>(m, "LogASN");

    m.def("get_LogMsgASN", &get_LogMsgASN,
          py::arg("log_msg"),
          py::arg("log_index"));

    m.def("get_LogIntValueASN", &get_LogIntValueASN,
          py::arg("log_msg"),
          py::arg("log_value"),
          py::arg("log_index"));

    m.def("get_LogStringValueASN", &get_LogStringValueASN,
          py::arg("log_msg"),
          py::arg("str_value"),
          py::arg("log_index"));

    m.def("get_LogMsgASN", &get_LogMsgASN,
          py::arg("log_msg"),
          py::arg("log_index"));

    m.def("encode_LogASN", &encode_LogASN,
    py::arg("log_asn"));

    m.def("decode_LogASN", &decode_LogASN,
    py::arg("bytes_to_decode"));

    m.def("get_log_string", &get_log_string,
    py::arg("log_asn"));


    // Constants

    m.attr("INJECTION_CONFIGURATION_ASN_ENCODING_BYTE") = py::int_(InjectionConfigurationASN_REQUIRED_BYTES_FOR_ENCODING);
    m.attr("INJECTION_ACTION_ASN_ENCODING_BYTES") = py::int_(InjectionActionASN_REQUIRED_BYTES_FOR_ENCODING);
    m.attr("EXCHANGE_STATUS_ASN_ENCODING_BYTES") = py::int_(ExchangeStatusASN_REQUIRED_BYTES_FOR_ENCODING);
    m.attr("LOG_MSG_ASN_ENCODING_BYTES") = py::int_(LogMsgASN_REQUIRED_BITS_FOR_ENCODING);
}