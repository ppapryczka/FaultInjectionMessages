#include "log_asn_api.h"

#include <cstring>

LogASN get_LogMsgASN(const std::string& log_msg, uint32_t log_index){
    LogASN log_asn;

    log_asn.logChoice.kind = LogChoiceASN::logMsg_PRESENT;

    // ugly array operations
    memcpy(log_asn.logDescription.arr, log_msg.c_str(), kLogStringMaxLength);
    log_asn.logDescription.arr[kLogStringMaxLength-1] = '\0';

    log_asn.logIndex = log_index;

    int errorCode;
    if(!LogASN_IsConstraintValid(&log_asn, &errorCode)){
        throw std::runtime_error("Given values are inappropriate! Error code: " + std::to_string(errorCode)+".");
    }

    return log_asn;
}

LogASN get_LogIntValueASN(const std::string& log_msg, uint32_t log_value, uint32_t log_index){
    LogASN log_asn;

    log_asn.logChoice.kind = LogChoiceASN::logIntValue_PRESENT;

    // ugly array operations
    memcpy(log_asn.logDescription.arr, log_msg.c_str(), kLogStringMaxLength);
    log_asn.logDescription.arr[kLogStringMaxLength-1] = '\0';

    log_asn.logChoice.u.logIntValue.intValue = log_value;
    log_asn.logIndex = log_index;

    int errorCode;
    if(!LogASN_IsConstraintValid(&log_asn, &errorCode)){
        throw std::runtime_error("Given values are inappropriate! Error code: " + std::to_string(errorCode)+".");
    }

    return log_asn;
}

LogASN get_LogStringValueASN(const std::string& log_msg, const std::string& str_value, uint32_t log_index){
    LogASN log_asn;

    log_asn.logChoice.kind = LogChoiceASN::logStringValue_PRESENT;

    // ugly array operations
    memcpy(log_asn.logDescription.arr, log_msg.c_str(), kLogStringMaxLength);
    log_asn.logDescription.arr[kLogStringMaxLength-1] = '\0';

    memcpy(log_asn.logChoice.u.logStringValue.stringValue.arr, str_value.c_str(), kLogStringMaxLength);
    log_asn.logChoice.u.logStringValue.stringValue.arr[kLogStringMaxLength-1] = '\0';

    log_asn.logIndex = log_index;

    int errorCode;
    if(!LogASN_IsConstraintValid(&log_asn, &errorCode)){
        throw std::runtime_error("Given values are inappropriate! Error code: " + std::to_string(errorCode)+".");
    }

    return log_asn;
}

std::array<byte, LogASN_REQUIRED_BYTES_FOR_ENCODING> encode_LogASN(const LogASN& log_asn){
    std::array<byte, LogASN_REQUIRED_BYTES_FOR_ENCODING> byteBuffer{};
    int errorCode;
    BitStream bitStream;

    BitStream_Init(&bitStream, byteBuffer.data(), LogASN_REQUIRED_BYTES_FOR_ENCODING);

    if(!LogASN_Encode(&log_asn, &bitStream, &errorCode, TRUE)) {
        throw std::runtime_error("Encode error! Error code: "+std::to_string(errorCode)+".");
    }
    return byteBuffer;
}

LogASN decode_LogASN(std::array<byte, LogASN_REQUIRED_BYTES_FOR_ENCODING>& bytes_to_decode){
    LogASN log_asn;
    int errorCode;
    BitStream bitStream_decode;

    BitStream_AttachBuffer(&bitStream_decode, bytes_to_decode.data(), bytes_to_decode.size());

    if (!LogASN_Decode(&log_asn, &bitStream_decode, &errorCode)){
        throw std::runtime_error("Decode error! Error code: "+std::to_string(errorCode)+".");
    }

    return log_asn;
}

std::string get_log_string(const LogASN& log_asn){
    std::string log_string;
    if (log_asn.logChoice.kind == LogChoiceASN::logMsg_PRESENT){
        log_string+="Type: MSG"        ;
        log_string+=" Description: ";
        log_string+=(char*)(log_asn.logDescription.arr);
    } else if (log_asn.logChoice.kind == LogChoiceASN::logIntValue_PRESENT){
        log_string+="Type: String value";
        log_string+=" Description: ";
        log_string+=(char*)(log_asn.logDescription.arr);
        log_string+=" String value:";
        log_string+=(char*)(log_asn.logChoice.u.logStringValue.stringValue.arr);
    } else if (log_asn.logChoice.kind == LogChoiceASN::logStringValue_PRESENT){
        log_string+="Type: Int value"  ;
        log_string+=" Description: ";
        log_string+=(char*)(log_asn.logDescription.arr);
        log_string+=" Int value: ";
        log_string+=std::to_string(log_asn.logChoice.u.logIntValue.intValue);
    } else {
        log_string = "Unknown log type - happened something unexpected!";
    }

    return log_string;
}