#include "injection_action_asn_api.h"

InjectionActionASN get_RegisterInjectionActionASN(uint32_t injection_address,
                                            uint32_t register_index,
                                            uint32_t value_mask,
                                            uint32_t omit_calls_number,
                                            MaskOperationASN mask_operation,
                                            uint32_t injection_index){

    RegisterInjectionActionASN register_injection_action;
    register_injection_action.injectionAddress = injection_address;
    register_injection_action.registerIndex = register_index;
    register_injection_action.valueMask = value_mask;
    register_injection_action.omitCallsNumber = omit_calls_number;
    register_injection_action.maskOperation = mask_operation;

    int errorCode;
    if(!RegisterInjectionActionASN_IsConstraintValid(&register_injection_action, &errorCode)){
        throw std::runtime_error("Given values are inappropriate! Error code: " + std::to_string(errorCode)+".");
    }

    InjectionActionChoiceASN injection_action_choice;
    injection_action_choice.kind = InjectionActionChoiceASN::registerAction_PRESENT;
    injection_action_choice.u.registerAction = register_injection_action;

    if(!InjectionActionChoiceASN_IsConstraintValid(&injection_action_choice, &errorCode)){
        throw std::runtime_error("Given values are inappropriate! Error code: " + std::to_string(errorCode)+".");
    }

    InjectionActionASN injection_action;
    injection_action.injectionAction = injection_action_choice;
    injection_action.injectionActionIndex = injection_index;

    if(!InjectionActionASN_IsConstraintValid(&injection_action, &errorCode)){
        throw std::runtime_error("Given values are inappropriate! Error code: " + std::to_string(errorCode)+".");
    }

    return injection_action;
}

InjectionActionASN get_MemoryInjectionActionASN(uint32_t injection_address,
                                          uint32_t memory_address,
                                          uint32_t value_mask,
                                          uint32_t omit_calls_number,
                                          MaskOperationASN mask_operation,
                                          uint32_t injection_index){

    MemoryInjectionActionASN memory_injection_action;
    memory_injection_action.injectionAddress = injection_address;
    memory_injection_action.memoryAddress = memory_address;
    memory_injection_action.valueMask = value_mask;
    memory_injection_action.omitCallsNumber = omit_calls_number;
    memory_injection_action.maskOperation = mask_operation;

    int errorCode;
    if(!MemoryInjectionActionASN_IsConstraintValid(&memory_injection_action, &errorCode)){
        throw std::runtime_error("Given values are inappropriate! Error code: " + std::to_string(errorCode)+".");
    }

    InjectionActionChoiceASN injection_action_choice;
    injection_action_choice.kind = InjectionActionChoiceASN::memoryAction_PRESENT;
    injection_action_choice.u.memoryAction = memory_injection_action;

    if(!InjectionActionChoiceASN_IsConstraintValid(&injection_action_choice, &errorCode)){
        throw std::runtime_error("Given values are inappropriate! Error code: " + std::to_string(errorCode)+".");
    }

    InjectionActionASN injection_action;
    injection_action.injectionAction = injection_action_choice;
    injection_action.injectionActionIndex = injection_index;

    if(!InjectionActionASN_IsConstraintValid(&injection_action, &errorCode)){
        throw std::runtime_error("Given values are inappropriate! Error code: " + std::to_string(errorCode)+".");
    }

    return injection_action;
}

std::array<byte, InjectionActionASN_REQUIRED_BYTES_FOR_ENCODING> encode_InjectionActionASN(const InjectionActionASN& injection_action){
    std::array<byte, InjectionActionASN_REQUIRED_BYTES_FOR_ENCODING> byteBuffer{};
    int errorCode;
    BitStream bitStream;

    BitStream_Init(&bitStream, byteBuffer.data(), InjectionActionASN_REQUIRED_BYTES_FOR_ENCODING);

    if(!InjectionActionASN_Encode(&injection_action, &bitStream, &errorCode, TRUE)) {
        throw std::runtime_error("Encode error! Error code: "+std::to_string(errorCode)+".");
    }
    return byteBuffer;
}

InjectionActionASN decode_InjectionActionASN(std::array<byte, InjectionActionASN_REQUIRED_BYTES_FOR_ENCODING>& bytes_to_decode){
    InjectionActionASN injection_action;
    int errorCode;
    BitStream bitStream_decode;

    BitStream_AttachBuffer(&bitStream_decode, bytes_to_decode.data(), bytes_to_decode.size());

    if (!InjectionActionASN_Decode(&injection_action, &bitStream_decode, &errorCode)){
        throw std::runtime_error("Decode error! Error code: "+std::to_string(errorCode)+".");
    }

    return injection_action;
}

