#include "injection_configuration_asn_api.h"

InjectionConfigurationASN get_InjectionConfigurationASN(bool logging,
                                                        uint32_t register_injection_actions,
                                                        uint32_t memory_injection_actions){
    InjectionConfigurationASN configuration;

    configuration.logging = logging;
    configuration.registerInjectionActionsNum = register_injection_actions;
    configuration.memoryInjectionActionsNum = memory_injection_actions;
    configuration.injectionActionsNum = register_injection_actions + memory_injection_actions;

    int errorCode;
    if(!InjectionConfigurationASN_IsConstraintValid(&configuration, &errorCode)){
        throw std::runtime_error("Given values are inappropriate! Error code: " + std::to_string(errorCode)+".");
    }

    return configuration;
}

std::array<byte, InjectionConfigurationASN_REQUIRED_BYTES_FOR_ENCODING> encode_InjectionConfigurationASN(const InjectionConfigurationASN &configuration){
    std::array<byte, InjectionConfigurationASN_REQUIRED_BYTES_FOR_ENCODING> byteBuffer{};
    int errorCode;
    BitStream bitStream;

    BitStream_Init(&bitStream, byteBuffer.data(), InjectionConfigurationASN_REQUIRED_BYTES_FOR_ENCODING);

    if(!InjectionConfigurationASN_Encode(&configuration, &bitStream, &errorCode, TRUE)) {
        throw std::runtime_error("Encode error! Error code: "+std::to_string(errorCode)+".");
    }
    return byteBuffer;
}

InjectionConfigurationASN decode_InjectionConfigurationASN(std::array<byte, InjectionConfigurationASN_REQUIRED_BYTES_FOR_ENCODING>& bytes_to_decode){
    InjectionConfigurationASN configuration;
    int errorCode;
    BitStream bitStream_decode;

    BitStream_AttachBuffer(&bitStream_decode, bytes_to_decode.data(), bytes_to_decode.size());

    if (!InjectionConfigurationASN_Decode(&configuration, &bitStream_decode, &errorCode)){
        throw std::runtime_error("Decode error! Error code: "+std::to_string(errorCode)+".");
    }

    return configuration;
}
