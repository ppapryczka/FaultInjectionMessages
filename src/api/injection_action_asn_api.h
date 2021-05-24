#ifndef FAULTINJECTIONMESSAGE_INJECTION_ACTION_ASN_API_H
#define FAULTINJECTIONMESSAGE_INJECTION_ACTION_ASN_API_H

#include "../asn_files/fault_injection_messages.h"

#include <array>
#include <cstdint>

/**
 * Get ASN register injection action object from given parameters.
 *
 * @param injection_address Address of injection trigger.
 * @param register_index Index of register.
 * @param value_mask Value mask of register.
 * @param omit_calls_number Number of commits to omit.
 * @param mask_operation Mask operation.
 * @param injection_index Index of injection action.
 *
 * @throws runtime_error When given values don't match constraints.
 *
 * @return Object constructed from parameters.
 */
InjectionActionASN get_RegisterInjectionActionASN(uint32_t injection_address,
                                                  uint32_t register_index,
                                                  uint32_t value_mask,
                                                  uint32_t omit_calls_number,
                                                  MaskOperationASN mask_operation,
                                                  uint32_t injection_index);

/**
 * Get ASN memory injection action object from given parameters.
 *
 * @param injection_address Address of injection trigger.
 * @param memory_address Address of memory to inject.
 * @param value_mask Value mask of register.
 * @param omit_calls_number Number of commits to omit.
 * @param mask_operation Mask operation.
 * @param injection_index Index of injection action.
 *
 * @throws runtime_error When given values don't match constraints.
 *
 * @return Object constructed from parameters.
 */
InjectionActionASN get_MemoryInjectionActionASN(uint32_t injection_address,
                                                uint32_t memory_address,
                                                uint32_t value_mask,
                                                uint32_t omit_calls_number,
                                                MaskOperationASN mask_operation,
                                                uint32_t injection_index);

/**
 * Encode given ASN injection action into array of byte.
 *
 * @param injection_action ASN injection action to encode.
 *
 * @throws runtime_error When encode error occur.
 *
 * @return Byte array representation of decoded injection action.
 */
std::array<byte, InjectionActionASN_REQUIRED_BYTES_FOR_ENCODING> encode_InjectionActionASN(const InjectionActionASN& injection_action);

/**
 * Decode ASN injection action from given array of byte.
 *
 * @param bytes_to_decode Byte array to decode ASN injection action from.
 *
 * @throws runtime_error When decode error occur.
 *
 * @return Decoded ASN injection action.
 */
InjectionActionASN decode_InjectionActionASN(std::array<byte, InjectionActionASN_REQUIRED_BYTES_FOR_ENCODING>& bytes_to_decode);

#endif //FAULTINJECTIONMESSAGE_INJECTION_ACTION_ASN_API_H
