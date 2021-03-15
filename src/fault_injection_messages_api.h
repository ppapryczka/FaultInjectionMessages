#ifndef FAULTINJECTIONMESSAGE_FAULT_INJECTION_MESSAGES_API_H
#define FAULTINJECTIONMESSAGE_FAULT_INJECTION_MESSAGES_API_H

#include <array>
#include <algorithm>
#include <cstddef>
#include <cstdint>

#include "fault_injection_messages.h"


// INJECTION CONFIGURATION

InjectionConfiguration get_InjectionConfiguration(bool logging, uint32_t register_injection_actions, uint32_t memory_injection_actions);

std::array<byte, InjectionConfiguration_REQUIRED_BYTES_FOR_ENCODING> encode_InjectionConfiguration(const InjectionConfiguration &injection_configuration);

InjectionConfiguration decode_InjectionConfiguration(std::array<byte, InjectionConfiguration_REQUIRED_BYTES_FOR_ENCODING>& bytes_to_decode);


// INJECTION ACTION

InjectionAction get_RegisterInjectionAction(uint32_t injection_address,
                                            uint32_t register_index,
                                            uint32_t value_mask,
                                            uint32_t omit_calls_number,
                                            MaskOperation mask_operation,
                                            uint32_t injection_index);

InjectionAction get_MemoryInjectionAction(uint32_t injection_address,
                                          uint32_t memory_address,
                                          uint32_t value_mask,
                                          uint32_t omit_calls_number,
                                          MaskOperation mask_operation,
                                          uint32_t injection_index);

std::array<byte, InjectionAction_REQUIRED_BYTES_FOR_ENCODING> encode_InjectionAction(const InjectionAction& injection_action);

InjectionAction decode_InjectionAction(std::array<byte, InjectionConfiguration_REQUIRED_BYTES_FOR_ENCODING>& bytes_to_decode);

// EXCHANGE STATUS

ExchangeStatus get_ExchangeStatus(const ExchangeStatusEnum& exchange_status_enum);

std::array<byte, ExchangeStatus_REQUIRED_BYTES_FOR_ENCODING> encode_ExchangeStatus(const ExchangeStatus& exchange_status);

ExchangeStatus decode_ExchangeStatus(std::array<byte, ExchangeStatus_REQUIRED_BYTES_FOR_ENCODING>& bytes_to_decode);


#endif //FAULTINJECTIONMESSAGE_FAULT_INJECTION_MESSAGES_API_H
