#include "../src/asn_files/fault_injection_messages.h"
#include "../src/api/exchange_status_asn_api.h"

#include "catch2/catch.hpp"



TEST_CASE("ExchangeStatus::get_RegisterInjectionAction"){
    SECTION("Create object 1"){
        auto status_enum = ExchangeStatusEnumASN::waitingConf;
        auto exchange_obj = get_ExchangeStatusASN(status_enum);
        REQUIRE(exchange_obj.status == status_enum);
    }

    SECTION("Create object 2"){
        auto status_enum = ExchangeStatusEnumASN::sendingActions;
        auto exchange_obj = get_ExchangeStatusASN(status_enum);
        REQUIRE(exchange_obj.status == status_enum);
    }

    SECTION("Create object 3"){
        auto status_enum = ExchangeStatusEnumASN::actionsReceived;
        auto exchange_obj = get_ExchangeStatusASN(status_enum);
        REQUIRE(exchange_obj.status == status_enum);
    }
}

TEST_CASE("ExchangeStatus::encode_decode_tests") {
    SECTION("Encode and decode object 1") {
        auto status_enum = ExchangeStatusEnumASN::waitingConf;
        auto exchange_obj = get_ExchangeStatusASN(status_enum);

        // decode
        auto exchange_encoded = encode_ExchangeStatusASN(exchange_obj);

        // encode
        auto exchange_decoded = decode_ExchangeStatusASN(exchange_encoded);

        REQUIRE(exchange_obj.status == exchange_decoded.status);
    }

    SECTION("Encode and decode object 2") {
        auto status_enum = ExchangeStatusEnumASN::sendingActions;
        auto exchange_obj = get_ExchangeStatusASN(status_enum);

        // decode
        auto exchange_encoded = encode_ExchangeStatusASN(exchange_obj);

        // encode
        auto exchange_decoded = decode_ExchangeStatusASN(exchange_encoded);

        REQUIRE(exchange_obj.status == exchange_decoded.status);
    }

    SECTION("Encode and decode object 3") {
        auto status_enum = ExchangeStatusEnumASN::actionsReceived;
        auto exchange_obj = get_ExchangeStatusASN(status_enum);

        // decode
        auto exchange_encoded = encode_ExchangeStatusASN(exchange_obj);

        // encode
        auto exchange_decoded = decode_ExchangeStatusASN(exchange_encoded);

        REQUIRE(exchange_obj.status == exchange_decoded.status);
    }
}

TEST_CASE("ExchangeStatus::decode_state_and_check_if_is_expected"){
    auto exchange_obj_1 = get_ExchangeStatusASN(ExchangeStatusEnumASN::waitingConf);
    auto exchange_obj_2 = get_ExchangeStatusASN(ExchangeStatusEnumASN::actionsReceived);

    auto exchange_obj_1_encoded = encode_ExchangeStatusASN(exchange_obj_1);
    auto exchange_obj_2_encoded = encode_ExchangeStatusASN(exchange_obj_2);

    REQUIRE(decode_state_and_check_if_is_expected(exchange_obj_1_encoded, ExchangeStatusEnumASN::waitingConf));
    REQUIRE(decode_state_and_check_if_is_expected(exchange_obj_2_encoded, ExchangeStatusEnumASN::actionsReceived));
    REQUIRE(!decode_state_and_check_if_is_expected(exchange_obj_1_encoded, ExchangeStatusEnumASN::sendingActions));
}