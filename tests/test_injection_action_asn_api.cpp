#include "../src/asn_files/fault_injection_messages.h"
#include "../src/api/injection_action_asn_api.h"

#include "catch2/catch.hpp"

void compare_RegisterInjectionActionASN_objects(const InjectionActionASN& first, const InjectionActionASN &second){
    REQUIRE(first.injectionAction.kind == InjectionActionChoiceASN::registerAction_PRESENT);
    REQUIRE(first.injectionAction.kind == second.injectionAction.kind);
    REQUIRE(first.injectionAction.u.registerAction.injectionAddress == second.injectionAction.u.registerAction.injectionAddress);
    REQUIRE(first.injectionAction.u.registerAction.injectionAddress == second.injectionAction.u.registerAction.injectionAddress);
    REQUIRE(first.injectionAction.u.registerAction.valueMask == second.injectionAction.u.registerAction.valueMask);
    REQUIRE(first.injectionAction.u.registerAction.omitCallsNumber == second.injectionAction.u.registerAction.omitCallsNumber);
    REQUIRE(first.injectionAction.u.registerAction.maskOperation == second.injectionAction.u.registerAction.maskOperation);
    REQUIRE(first.injectionActionIndex == second.injectionActionIndex);
}

void compare_MemoryInjectionActionASN_objects(const InjectionActionASN& first, const InjectionActionASN &second){
    REQUIRE(first.injectionAction.kind == InjectionActionChoiceASN::memoryAction_PRESENT);
    REQUIRE(first.injectionAction.kind == second.injectionAction.kind);
    REQUIRE(first.injectionAction.u.registerAction.injectionAddress == second.injectionAction.u.registerAction.injectionAddress);
    REQUIRE(first.injectionAction.u.registerAction.injectionAddress == second.injectionAction.u.registerAction.injectionAddress);
    REQUIRE(first.injectionAction.u.registerAction.valueMask == second.injectionAction.u.registerAction.valueMask);
    REQUIRE(first.injectionAction.u.registerAction.omitCallsNumber == second.injectionAction.u.registerAction.omitCallsNumber);
    REQUIRE(first.injectionAction.u.registerAction.maskOperation == second.injectionAction.u.registerAction.maskOperation);
    REQUIRE(first.injectionActionIndex == second.injectionActionIndex);
}

TEST_CASE("RegisterInjectionAction::get_RegisterInjectionAction"){
    SECTION("Create object 1"){
        int32_t injection_address = 1001;
        uint32_t register_index = 4;
        uint32_t value_mask = 1002;
        uint32_t omit_calls_number = 3;
        MaskOperationASN mask_operation = MaskOperationASN::xorOperation;
        uint32_t injection_index = 3;

        auto injection_action = get_RegisterInjectionActionASN(
                injection_address,
                register_index,
                value_mask,
                omit_calls_number,
                mask_operation,
                injection_index);

        REQUIRE(injection_action.injectionAction.kind == InjectionActionChoiceASN::registerAction_PRESENT);
        REQUIRE(injection_action.injectionAction.u.registerAction.injectionAddress == injection_address);
        REQUIRE(injection_action.injectionAction.u.registerAction.registerIndex == register_index);
        REQUIRE(injection_action.injectionAction.u.registerAction.valueMask == value_mask);
        REQUIRE(injection_action.injectionAction.u.registerAction.omitCallsNumber == omit_calls_number);
        REQUIRE(injection_action.injectionAction.u.registerAction.maskOperation == mask_operation);
        REQUIRE(injection_action.injectionActionIndex == injection_index);
    }

    SECTION("Create object 2"){
        int32_t injection_address = 99;
        uint32_t register_index = 3;
        uint32_t value_mask = 874;
        uint32_t omit_calls_number = 10;
        MaskOperationASN mask_operation = MaskOperationASN::setOperation;
        uint32_t injection_index = 4;

        auto injection_action = get_RegisterInjectionActionASN(
                injection_address,
                register_index,
                value_mask,
                omit_calls_number,
                mask_operation,
                injection_index);

        REQUIRE(injection_action.injectionAction.kind == InjectionActionChoiceASN::registerAction_PRESENT);
        REQUIRE(injection_action.injectionAction.u.registerAction.injectionAddress == injection_address);
        REQUIRE(injection_action.injectionAction.u.registerAction.registerIndex == register_index);
        REQUIRE(injection_action.injectionAction.u.registerAction.valueMask == value_mask);
        REQUIRE(injection_action.injectionAction.u.registerAction.omitCallsNumber == omit_calls_number);
        REQUIRE(injection_action.injectionAction.u.registerAction.maskOperation == mask_operation);
        REQUIRE(injection_action.injectionActionIndex == injection_index);
    }
}

TEST_CASE("RegisterInjectionAction::encode_decode_tests"){
    SECTION("Encode and decode object 1"){
        int32_t injection_address = 99;
        uint32_t register_index = 3;
        uint32_t value_mask = 874;
        uint32_t omit_calls_number = 10;
        MaskOperationASN mask_operation = MaskOperationASN::setOperation;
        uint32_t injection_index = 4;

        auto injection_action = get_RegisterInjectionActionASN(
                injection_address,
                register_index,
                value_mask,
                omit_calls_number,
                mask_operation,
                injection_index);

        // encode
        auto injection_action_encode = encode_InjectionActionASN(injection_action);

        // decode
        auto injection_action_decode = decode_InjectionActionASN(injection_action_encode);

        compare_RegisterInjectionActionASN_objects(injection_action, injection_action_decode);
    }

    SECTION("Encode and decode object 2"){
        int32_t injection_address = 99;
        uint32_t register_index = 3;
        uint32_t value_mask = 874;
        uint32_t omit_calls_number = 10;
        MaskOperationASN mask_operation = MaskOperationASN::setOperation;
        uint32_t injection_index = 4;

        auto injection_action = get_RegisterInjectionActionASN(
                injection_address,
                register_index,
                value_mask,
                omit_calls_number,
                mask_operation,
                injection_index);

        // encode
        auto injection_action_encode = encode_InjectionActionASN(injection_action);

        // decode
        auto injection_action_decode = decode_InjectionActionASN(injection_action_encode);

        compare_RegisterInjectionActionASN_objects(injection_action, injection_action_decode);
    }
}

TEST_CASE("MemoryInjectionAction::get_MemoryInjectionAction"){
    SECTION("Create object 1"){
        int32_t injection_address = 1001;
        uint32_t memory_address = 10010;
        uint32_t value_mask = 1002;
        uint32_t omit_calls_number = 3;
        MaskOperationASN mask_operation = MaskOperationASN::xorOperation;
        uint32_t injection_index = 3;

        auto injection_action = get_MemoryInjectionActionASN(
                injection_address,
                memory_address,
                value_mask,
                omit_calls_number,
                mask_operation,
                injection_index);

        REQUIRE(injection_action.injectionAction.kind == InjectionActionChoiceASN::memoryAction_PRESENT);
        REQUIRE(injection_action.injectionAction.u.memoryAction.injectionAddress == injection_address);
        REQUIRE(injection_action.injectionAction.u.memoryAction.memoryAddress == memory_address);
        REQUIRE(injection_action.injectionAction.u.memoryAction.valueMask == value_mask);
        REQUIRE(injection_action.injectionAction.u.memoryAction.omitCallsNumber == omit_calls_number);
        REQUIRE(injection_action.injectionAction.u.memoryAction.maskOperation == mask_operation);
        REQUIRE(injection_action.injectionActionIndex == injection_index);
    }

    SECTION("Create object 2"){
        int32_t injection_address = 34;
        uint32_t memory_address = 567;
        uint32_t value_mask = 45;
        uint32_t omit_calls_number = 78;
        MaskOperationASN mask_operation = MaskOperationASN::orOperation;
        uint32_t injection_index = 2;

        auto injection_action = get_MemoryInjectionActionASN(
                injection_address,
                memory_address,
                value_mask,
                omit_calls_number,
                mask_operation,
                injection_index);

        REQUIRE(injection_action.injectionAction.kind == InjectionActionChoiceASN::memoryAction_PRESENT);
        REQUIRE(injection_action.injectionAction.u.memoryAction.injectionAddress == injection_address);
        REQUIRE(injection_action.injectionAction.u.memoryAction.memoryAddress == memory_address);
        REQUIRE(injection_action.injectionAction.u.memoryAction.valueMask == value_mask);
        REQUIRE(injection_action.injectionAction.u.memoryAction.omitCallsNumber == omit_calls_number);
        REQUIRE(injection_action.injectionAction.u.memoryAction.maskOperation == mask_operation);
        REQUIRE(injection_action.injectionActionIndex == injection_index);
    }
}


TEST_CASE("MemoryInjectionAction::encode_decode_tests"){
    SECTION("Encode and decode object 1"){
        int32_t injection_address = 1001;
        uint32_t memory_address = 10010;
        uint32_t value_mask = 1002;
        uint32_t omit_calls_number = 3;
        MaskOperationASN mask_operation = MaskOperationASN::xorOperation;
        uint32_t injection_index = 3;

        auto injection_action = get_MemoryInjectionActionASN(
                injection_address,
                memory_address,
                value_mask,
                omit_calls_number,
                mask_operation,
                injection_index);

        // encode
        auto injection_action_encode = encode_InjectionActionASN(injection_action);

        // decode
        auto injection_action_decode = decode_InjectionActionASN(injection_action_encode);

        compare_MemoryInjectionActionASN_objects(injection_action, injection_action_decode);
    }

    SECTION("Encode and decode object 2"){
        int32_t injection_address = 34;
        uint32_t memory_address = 567;
        uint32_t value_mask = 45;
        uint32_t omit_calls_number = 78;
        MaskOperationASN mask_operation = MaskOperationASN::orOperation;
        uint32_t injection_index = 2;

        auto injection_action = get_MemoryInjectionActionASN(
                injection_address,
                memory_address,
                value_mask,
                omit_calls_number,
                mask_operation,
                injection_index);

        // encode
        auto injection_action_encode = encode_InjectionActionASN(injection_action);

        // decode
        auto injection_action_decode = decode_InjectionActionASN(injection_action_encode);

        compare_MemoryInjectionActionASN_objects(injection_action, injection_action_decode);
    }
}