#include "fault_injection_messages_api.h"

// INJECTION CONFIGURATION

InjectionConfiguration get_InjectionConfiguration(bool logging,
                                                  uint32_t register_injection_actions,
                                                  uint32_t memory_injection_actions){
    InjectionConfiguration configuration;

    configuration.logging = logging;
    configuration.registerInjectionActionsNum = register_injection_actions;
    configuration.memoryInjectionActionsNum = memory_injection_actions;
    configuration.injectionActionsNum = register_injection_actions + memory_injection_actions;

    int errorCode;
    if(!InjectionConfiguration_IsConstraintValid(&configuration, &errorCode)){
        throw std::runtime_error("Given values are inappropriate! Error code: " + std::to_string(errorCode)+".");
    }

    return configuration;
}

std::array<byte, InjectionConfiguration_REQUIRED_BYTES_FOR_ENCODING> encode_InjectionConfiguration(const InjectionConfiguration &configuration){
    std::array<byte, InjectionConfiguration_REQUIRED_BYTES_FOR_ENCODING> byteBuffer{};
    int errorCode;
    BitStream bitStream;

    BitStream_Init(&bitStream, byteBuffer.data(), InjectionConfiguration_REQUIRED_BYTES_FOR_ENCODING);

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

// INJECTION ACTION

InjectionAction get_RegisterInjectionAction(uint32_t injection_address,
                                            uint32_t register_index,
                                            uint32_t value_mask,
                                            uint32_t omit_calls_number,
                                            MaskOperation mask_operation,
                                            uint32_t injection_index){

    RegisterInjectionAction register_injection_action;
    register_injection_action.injectionAddress = injection_address;
    register_injection_action.registerIndex = register_index;
    register_injection_action.valueMask = value_mask;
    register_injection_action.omitCallsNumber = omit_calls_number;
    register_injection_action.maskOperation = mask_operation;

    int errorCode;
    if(!RegisterInjectionAction_IsConstraintValid(&register_injection_action, &errorCode)){
        throw std::runtime_error("Given values are inappropriate! Error code: " + std::to_string(errorCode)+".");
    }

    InjectionActionChoice injection_action_choice;
    injection_action_choice.kind = InjectionActionChoice::registerAction_PRESENT;
    injection_action_choice.u.registerAction = register_injection_action;

    if(!InjectionActionChoice_IsConstraintValid(&injection_action_choice, &errorCode)){
        throw std::runtime_error("Given values are inappropriate! Error code: " + std::to_string(errorCode)+".");
    }

    InjectionAction injection_action;
    injection_action.injectionAction = injection_action_choice;
    injection_action.injectionActionIndex = injection_index;

    if(!InjectionAction_IsConstraintValid(&injection_action, &errorCode)){
        throw std::runtime_error("Given values are inappropriate! Error code: " + std::to_string(errorCode)+".");
    }

    return injection_action;
}

InjectionAction get_MemoryInjectionAction(uint32_t injection_address,
                                          uint32_t memory_address,
                                          uint32_t value_mask,
                                          uint32_t omit_calls_number,
                                          MaskOperation mask_operation,
                                          uint32_t injection_index){

    MemoryInjectionAction memory_injection_action;
    memory_injection_action.injectionAddress = injection_address;
    memory_injection_action.memoryAddress = memory_address;
    memory_injection_action.valueMask = value_mask;
    memory_injection_action.omitCallsNumber = omit_calls_number;
    memory_injection_action.maskOperation = mask_operation;

    int errorCode;
    if(!MemoryInjectionAction_IsConstraintValid(&memory_injection_action, &errorCode)){
        throw std::runtime_error("Given values are inappropriate! Error code: " + std::to_string(errorCode)+".");
    }

    InjectionActionChoice injection_action_choice;
    injection_action_choice.kind = InjectionActionChoice::memoryAction_PRESENT;
    injection_action_choice.u.memoryAction = memory_injection_action;

    if(!InjectionActionChoice_IsConstraintValid(&injection_action_choice, &errorCode)){
        throw std::runtime_error("Given values are inappropriate! Error code: " + std::to_string(errorCode)+".");
    }

    InjectionAction injection_action;
    injection_action.injectionAction = injection_action_choice;
    injection_action.injectionActionIndex = injection_index;

    if(!InjectionAction_IsConstraintValid(&injection_action, &errorCode)){
        throw std::runtime_error("Given values are inappropriate! Error code: " + std::to_string(errorCode)+".");
    }

    return injection_action;
}

std::array<byte, InjectionAction_REQUIRED_BYTES_FOR_ENCODING> encode_InjectionAction(const InjectionAction& injection_action){
    std::array<byte, InjectionAction_REQUIRED_BYTES_FOR_ENCODING> byteBuffer{};
    int errorCode;
    BitStream bitStream;

    BitStream_Init(&bitStream, byteBuffer.data(), InjectionAction_REQUIRED_BYTES_FOR_ENCODING);

    if(!InjectionAction_Encode(&injection_action, &bitStream, &errorCode, TRUE)) {
        throw std::runtime_error("Encode error! Error code: "+std::to_string(errorCode)+".");
    }
    return byteBuffer;
}

InjectionAction decode_InjectionAction(std::array<byte, InjectionConfiguration_REQUIRED_BYTES_FOR_ENCODING>& bytes_to_decode){
    InjectionAction injection_action ;
    int errorCode;
    BitStream bitStream_decode;

    BitStream_AttachBuffer(&bitStream_decode, bytes_to_decode.data(), bytes_to_decode.size());

    if (!InjectionAction_Decode(&injection_action, &bitStream_decode, &errorCode)){
        throw std::runtime_error("Decode error! Error code: "+std::to_string(errorCode)+".");
    }

    return injection_action;
}

// EXCHANGE STATUS

ExchangeStatus get_ExchangeStatus(const ExchangeStatusEnum& exchange_status_enum){
    ExchangeStatus exchange_status;

    exchange_status.status = exchange_status_enum;

    int errorCode;
    if(!ExchangeStatus_IsConstraintValid(&exchange_status, &errorCode)){
        throw std::runtime_error("Given values are inappropriate! Error code: " + std::to_string(errorCode)+".");
    }

    return exchange_status;
}

std::array<byte, ExchangeStatus_REQUIRED_BYTES_FOR_ENCODING> encode_ExchangeStatus(const ExchangeStatus& exchange_status){
    std::array<byte, ExchangeStatus_REQUIRED_BYTES_FOR_ENCODING> byteBuffer{};
    int errorCode;
    BitStream bitStream;

    BitStream_Init(&bitStream, byteBuffer.data(), ExchangeStatus_REQUIRED_BYTES_FOR_ENCODING);

    if(!ExchangeStatus_Encode(&exchange_status, &bitStream, &errorCode, TRUE)) {
        throw std::runtime_error("Encode error! Error code: "+std::to_string(errorCode)+".");
    }
    return byteBuffer;
}

ExchangeStatus decode_ExchangeStatus(std::array<byte, ExchangeStatus_REQUIRED_BYTES_FOR_ENCODING>& bytes_to_decode){
    ExchangeStatus exchange_status ;
    int errorCode;
    BitStream bitStream_decode;

    BitStream_AttachBuffer(&bitStream_decode, bytes_to_decode.data(), bytes_to_decode.size());

    if (!ExchangeStatus_Decode(&exchange_status, &bitStream_decode, &errorCode)){
        throw std::runtime_error("Decode error! Error code: "+std::to_string(errorCode)+".");
    }

    return exchange_status;
}

bool decode_state_and_check_if_is_expected(std::array<byte, ExchangeStatus_REQUIRED_BYTES_FOR_ENCODING>& bytes_to_decode, const ExchangeStatusEnum& expected_state){
    try {
        ExchangeStatus state = decode_ExchangeStatus(bytes_to_decode);

        if (state.status == expected_state) {
            return true;
        } else {
            return false;
        }
    } catch (const std::runtime_error& ex){
        // runtime error is throw when there is decode error
        return false;
    }
}

