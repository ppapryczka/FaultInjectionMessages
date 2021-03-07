#ifndef FAULTINJECTIONMESSAGE_FAULT_INJECTION_MESSAGES_API_H
#define FAULTINJECTIONMESSAGE_FAULT_INJECTION_MESSAGES_API_H

#include <array>
#include <algorithm>
#include <cstddef>
#include <cstdint>

#include "fault_injection_messages.h"

constexpr std::array <int, 3> kEncodingLengths = {
        {InjectionConfiguration_REQUIRED_BYTES_FOR_ENCODING,
                RegisterInjectionAction_REQUIRED_BYTES_FOR_ENCODING,
                MemoryInjectionAction_REQUIRED_BYTES_FOR_ENCODING}
};

constexpr int kMessageSize = *std::max_element(std::begin(kEncodingLengths), std::end(kEncodingLengths));

InjectionConfiguration get_InjectionConfiguration(bool logging,
                                               uint32_t register_injection_actions,
                                               uint32_t memory_injection_actions);

std::array<byte, InjectionConfiguration_REQUIRED_BYTES_FOR_ENCODING> encode_InjectionConfiguration(const InjectionConfiguration &configuration);

InjectionConfiguration decode_InjectionConfiguration(std::array<byte, InjectionConfiguration_REQUIRED_BYTES_FOR_ENCODING>& bytes_to_decode);

RegisterInjectionAction get_RegisterInjectionAction();

MemoryInjectionAction get_MemoryInjectionAction();


#endif //FAULTINJECTIONMESSAGE_FAULT_INJECTION_MESSAGES_API_H
