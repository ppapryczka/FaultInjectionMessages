#ifndef FAULTINJECTIONMESSAGE_LOG_ASN_API_H
#define FAULTINJECTIONMESSAGE_LOG_ASN_API_H

#include "../asn_files/fault_injection_messages.h"

#include <array>

/**
 * Max length of log string.
 */
const uint32_t kLogStringMaxLength = 128;

/**
 * Create ASN log msg object.
 *
 * @param log_msg Log message.
 * @param log_index Index of log msg.
 *
 * @return Created ASN log msg.
 */
LogASN get_LogMsgASN(const std::string& log_msg, uint32_t log_index);

/**
 * Create ASN log msg with int value.
 *
 * @param log_msg Log message.
 * @param log_value Log integer value.
 * @param log_index Index of log msg.
 *
 * @return Created ASN log msg with int value.
 */
LogASN get_LogIntValueASN(const std::string& log_msg, uint32_t log_value, uint32_t log_index);

/**
 * Create ASN log msg with string  value.
 *
 * @param log_msg Log message.
 * @param str_value Log string value.
 * @param log_index Index of log msg.
 *
 * @return Created ASN log msg with int value.
 */
LogASN get_LogStringValueASN(const std::string& log_msg, const std::string& str_value, uint32_t log_index);

/**
 * Encode given ASN log into array of byte.
 *
 * @param log_asn ASN log to decode.
 *
 * @throws runtime_error When encode error occur.
 *
 * @return Byte array representation of decoded ASN log.
 */
std::array<byte, LogASN_REQUIRED_BYTES_FOR_ENCODING> encode_LogASN(const LogASN& log_asn);

/**
 * Decode ASN log from given array of byte.
 *
 * @param bytes_to_decode Byte array to decode ASN log from.
 *
 * @throws runtime_error When decode error occur.
 *
 * @return Decoded ASN log.
 */
LogASN decode_LogASN(std::array<byte, LogASN_REQUIRED_BYTES_FOR_ENCODING>& bytes_to_decode);

/**
 * Get string representation of log.
 *
 * @param log_asn ASN log to convert.
 *
 * @return ASN log string representation.
 */
std::string get_log_string(const LogASN& log_asn);

#endif //FAULTINJECTIONMESSAGE_LOG_ASN_API_H
