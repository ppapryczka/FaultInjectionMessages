#include "exchange_status_asn_api.h"

ExchangeStatusASN get_ExchangeStatusASN(const ExchangeStatusEnumASN & exchange_status_enum){
    ExchangeStatusASN exchange_status;

    exchange_status.status = exchange_status_enum;

    int errorCode;
    if(!ExchangeStatusASN_IsConstraintValid(&exchange_status, &errorCode)){
        throw std::runtime_error("Given values are inappropriate! Error code: " + std::to_string(errorCode)+".");
    }

    return exchange_status;
}

std::array<byte, ExchangeStatusASN_REQUIRED_BYTES_FOR_ENCODING> encode_ExchangeStatusASN(const ExchangeStatusASN& exchange_status){
    std::array<byte, ExchangeStatusASN_REQUIRED_BYTES_FOR_ENCODING> byteBuffer{};
    int errorCode;
    BitStream bitStream;

    BitStream_Init(&bitStream, byteBuffer.data(), ExchangeStatusASN_REQUIRED_BYTES_FOR_ENCODING);

    if(!ExchangeStatusASN_Encode(&exchange_status, &bitStream, &errorCode, TRUE)) {
        throw std::runtime_error("Encode error! Error code: "+std::to_string(errorCode)+".");
    }
    return byteBuffer;
}

ExchangeStatusASN decode_ExchangeStatusASN(std::array<byte, ExchangeStatusASN_REQUIRED_BYTES_FOR_ENCODING>& bytes_to_decode){
    ExchangeStatusASN exchange_status ;
    int errorCode;
    BitStream bitStream_decode;

    BitStream_AttachBuffer(&bitStream_decode, bytes_to_decode.data(), bytes_to_decode.size());

    if (!ExchangeStatusASN_Decode(&exchange_status, &bitStream_decode, &errorCode)){
        throw std::runtime_error("Decode error! Error code: "+std::to_string(errorCode)+".");
    }

    return exchange_status;
}

bool decode_state_and_check_if_is_expected(std::array<byte, ExchangeStatusASN_REQUIRED_BYTES_FOR_ENCODING>& bytes_to_decode,
                                           const ExchangeStatusEnumASN& expected_state){
    // decode
    ExchangeStatusASN state = decode_ExchangeStatusASN(bytes_to_decode);

    // compare statuses
    if (state.status == expected_state) {
        return true;
    } else {
        return false;
    }
}
