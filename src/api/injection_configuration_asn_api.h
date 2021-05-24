#ifndef FAULTINJECTIONMESSAGE_INJECTION_CONFIGURATION_ASN_API_H
#define FAULTINJECTIONMESSAGE_INJECTION_CONFIGURATION_ASN_API_H

#include "../asn_files/fault_injection_messages.h"

#include <array>
#include <cstdint>

/**
 * Create ASN injection configuration from given parameters.
 *
 * @param logging True if logging is turn on, false if not.
 * @param register_injection_actions Number of register injection actions.
 * @param memory_injection_actions Number of memory injection actions.
 *
 * @throws runtime_error When given values don't match constraints.
 *
 * @return Created injection configuration object.
 */
InjectionConfigurationASN get_InjectionConfigurationASN(bool logging, uint32_t register_injection_actions, uint32_t memory_injection_actions);

/**
 * Encode given ASN injection configuration into array of byte.
 *
 * @param injection_configuration ASN injection configuration to decode.
 *
 * @throws runtime_error When encode error occur.
 *
 * @return Byte array representation of decoded injection configuration.
 */
std::array<byte, InjectionConfigurationASN_REQUIRED_BYTES_FOR_ENCODING> encode_InjectionConfigurationASN(const InjectionConfigurationASN &injection_configuration);

/**
 * Decode ASN injection configuration from given array of byte.
 *
 * @param bytes_to_decode Byte array to decode ASN injection configuration from.
 *
 * @throws runtime_error When decode error occur.
 *
 * @return Decoded ASN injection configuration.
 */
InjectionConfigurationASN decode_InjectionConfigurationASN(std::array<byte, InjectionConfigurationASN_REQUIRED_BYTES_FOR_ENCODING>& bytes_to_decode);

#endif //FAULTINJECTIONMESSAGE_INJECTION_CONFIGURATION_ASN_API_H
