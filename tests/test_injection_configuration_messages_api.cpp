#include "../src/asn_files/fault_injection_messages.h"
#include "../src/api/injection_configuration_asn_api.h"

#include "catch2/catch.hpp"

void compare_InjectionConfigurationASN_objects(const InjectionConfigurationASN &first, const InjectionConfigurationASN &second){
    REQUIRE(first.logging == second.logging);
    REQUIRE(first.registerInjectionActionsNum == second.registerInjectionActionsNum);
    REQUIRE(first.memoryInjectionActionsNum == second.memoryInjectionActionsNum);
    REQUIRE(first.injectionActionsNum == second.injectionActionsNum);
}

TEST_CASE("InjectionConfigurationASN::get_InjectionConfigurationASN"){
    SECTION("Create object 1"){
        bool logging = true;
        uint32_t register_injection_actions = 10;
        uint32_t memory_injection_actions = 5;

        InjectionConfigurationASN ic_asn = get_InjectionConfigurationASN(logging,
                                                                         register_injection_actions,memory_injection_actions);
        REQUIRE(ic_asn.logging == logging);
        REQUIRE(ic_asn.injectionActionsNum == register_injection_actions+memory_injection_actions);
        REQUIRE(ic_asn.memoryInjectionActionsNum == memory_injection_actions);
        REQUIRE(ic_asn.registerInjectionActionsNum == register_injection_actions);
    }

    SECTION("Create object 2"){
        bool logging = false;
        uint32_t register_injection_actions = 3;
        uint32_t memory_injection_actions = 17;

        InjectionConfigurationASN ic_asn = get_InjectionConfigurationASN(logging,
                                                                         register_injection_actions,memory_injection_actions);
        REQUIRE(ic_asn.logging == logging);
        REQUIRE(ic_asn.injectionActionsNum == register_injection_actions+memory_injection_actions);
        REQUIRE(ic_asn.memoryInjectionActionsNum == memory_injection_actions);
        REQUIRE(ic_asn.registerInjectionActionsNum == register_injection_actions);
    }
}

TEST_CASE("InjectionConfigurationASN::encode_decode_tests"){
    SECTION("Encode and decode object 1"){
        bool logging = true;
        uint32_t register_injection_actions = 10;
        uint32_t memory_injection_actions = 5;
        InjectionConfigurationASN ic_asn = get_InjectionConfigurationASN(logging,
                                                                         register_injection_actions,memory_injection_actions);

        // encode
        auto ic_encoded = encode_InjectionConfigurationASN(ic_asn);

        // decode
        auto ic_decoded = decode_InjectionConfigurationASN(ic_encoded);

        compare_InjectionConfigurationASN_objects(ic_asn, ic_decoded);
    }

    SECTION("Create object 2"){
        bool logging = false;
        uint32_t register_injection_actions = 3;
        uint32_t memory_injection_actions = 17;
        InjectionConfigurationASN ic_asn = get_InjectionConfigurationASN(logging,
                                                                         register_injection_actions,memory_injection_actions);

        // encode
        auto ic_encoded = encode_InjectionConfigurationASN(ic_asn);

        // decode
        auto ic_decoded = decode_InjectionConfigurationASN(ic_encoded);

        compare_InjectionConfigurationASN_objects(ic_asn, ic_decoded);
    }
}