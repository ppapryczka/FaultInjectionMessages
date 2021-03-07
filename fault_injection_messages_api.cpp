#include "fault_injection_messages_api.h"


InjectionConfiguration get_InjectionConfiguration(bool logging,
                                               uint32_t register_injection_actions,
                                               uint32_t memory_injection_actions){
    InjectionConfiguration configuration;

    configuration.logging = logging;
    configuration.registerInjectionActionsNum = register_injection_actions;
    configuration.memoryInjectionActionsNum = memory_injection_actions;
    configuration.injectionActionsNum = register_injection_actions + memory_injection_actions;

    return configuration;
}

std::array<byte, InjectionConfiguration_REQUIRED_BYTES_FOR_ENCODING> encode_InjectionConfiguration(const InjectionConfiguration &configuration){
    std::array<byte, InjectionConfiguration_REQUIRED_BYTES_FOR_ENCODING> byteBuffer{};
    int errorCode;
    BitStream bitStream;

    BitStream_Init(&bitStream, byteBuffer.data(), kMessageSize);

    if(!InjectionConfiguration_Encode(&configuration, &bitStream, &errorCode, TRUE)) {
        throw std::runtime_error("Encode error! Error code: "+std::to_string(errorCode)+".");
    }
    return byteBuffer;
}

InjectionConfiguration decode_InjectionConfiguration(std::array<byte, InjectionConfiguration_REQUIRED_BYTES_FOR_ENCODING>& bytes_to_decode){
    InjectionConfiguration configuration;
    int errorCode;
    BitStream bitStream_decode;

    BitStream_AttachBuffer(&bitStream_decode, bytes_to_decode.data(), bytes_to_decode.size());

    if (!InjectionConfiguration_Decode(&configuration, &bitStream_decode, &errorCode)){
        throw std::runtime_error("Decode error! Error code: "+std::to_string(errorCode)+".");
    }

    return configuration;
}


