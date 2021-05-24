#ifndef FAULTINJECTIONMESSAGE_EXCHANGE_STATUS_ASN_API_H
#define FAULTINJECTIONMESSAGE_EXCHANGE_STATUS_ASN_API_H

#include "../asn_files/fault_injection_messages.h"

#include <array>

/**
 * Create ASN exchange status from given parameters.
 *
 * @param exchange_status_enum Status of exchange as enum value.
 *
 * @throws runtime_error When given values don't match constraints.
 *
 * @return Created injection configuration object.
 */
ExchangeStatusASN get_ExchangeStatusASN(const ExchangeStatusEnumASN& exchange_status_enum);

/**
 * Encode given ASN exchange status object into array of byte.
 *
 * @param exchange_status ASN exchange status object to encode.
 *
 * @throws runtime_error When encode error occur.
 *
 * @return Byte array representation of decoded exchange status.
 */
std::array<byte, ExchangeStatusASN_REQUIRED_BYTES_FOR_ENCODING> encode_ExchangeStatusASN(const ExchangeStatusASN& exchange_status);

/**
 * Decode given ASN exchange status object into array of byte.
 *
 * @param exchange_status ASN exchange status object to decode.
 *
 * @throws runtime_error When decode error occur.
 *
 * @return Byte array representation of decoded exchange status.
 */
ExchangeStatusASN decode_ExchangeStatusASN(std::array<byte, ExchangeStatusASN_REQUIRED_BYTES_FOR_ENCODING>& bytes_to_decode);

/**
 * Decode given exchange status and compare status with expected.
 *
 * @param bytes_to_decode ASN exchange status object to decode.
 * @param expected_state Expected exchange status object.
 *
 * @return True if decoded exchange status object have same status as expected, false instead,
 */
bool decode_state_and_check_if_is_expected(std::array<byte, ExchangeStatusASN_REQUIRED_BYTES_FOR_ENCODING>& bytes_to_decode,
                                           const ExchangeStatusEnumASN& expected_state);

#endif //FAULTINJECTIONMESSAGE_EXCHANGE_STATUS_ASN_API_H
