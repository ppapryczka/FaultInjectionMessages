#include <cstring>

#include "../src/asn_files/fault_injection_messages.h"
#include "../src/api/log_asn_api.h"

#include "catch2/catch.hpp"

TEST_CASE("LogMsgASN::get_LogMsgASN"){
    SECTION("Create object"){
        std::string msg = "msg";
        uint32_t log_index = 5;

        auto log_asn = get_LogMsgASN(msg, log_index);

        REQUIRE(log_asn.logChoice.kind==LogChoiceASN::logMsg_PRESENT);
        REQUIRE(strcpy((char*)log_asn.logDescription.arr, msg.c_str()));
        REQUIRE(log_asn.logIndex == log_index);
    }
}

TEST_CASE("LogIntValueASN::get_LogIntValueASN"){
    SECTION("Create object"){
        std::string msg = " int msg";
        uint32_t log_index = 3;
        uint32_t log_value = 21;

        auto log_asn = get_LogIntValueASN(msg, log_value,log_index);

        REQUIRE(log_asn.logChoice.kind==LogChoiceASN::logIntValue_PRESENT);
        REQUIRE(strcpy((char*)log_asn.logDescription.arr, msg.c_str()));
        REQUIRE(log_asn.logChoice.u.logIntValue.intValue == log_value);
        REQUIRE(log_asn.logIndex == log_index);
    }
}

TEST_CASE("LogStringValueASN::get_LogStringValueASN"){
    SECTION("Create object"){
        std::string msg = " int msg";
        uint32_t log_index = 3;
        std::string log_str_value = "msg value";

        auto log_asn = get_LogStringValueASN(msg, log_str_value, log_index);

        REQUIRE(log_asn.logChoice.kind==LogChoiceASN::logStringValue_PRESENT);
        REQUIRE(strcpy((char*)log_asn.logDescription.arr, msg.c_str()));
        REQUIRE(strcpy((char*)log_asn.logChoice.u.logStringValue.stringValue.arr, log_str_value.c_str()));
        REQUIRE(log_asn.logIndex == log_index);
    }
}

TEST_CASE("LogMsg:encode_decode_tests"){
    SECTION("LogMsg"){
        std::string msg = "msg";
        uint32_t log_index = 5;

        auto log_asn = get_LogMsgASN(msg, log_index);

        // encode
        auto log_encoded = encode_LogASN(log_asn);

        // decode
        auto log_decoded = decode_LogASN(log_encoded);

        REQUIRE(log_asn.logChoice.kind == log_decoded.logChoice.kind);
        REQUIRE(strcpy((char*)log_asn.logDescription.arr, (char*)log_decoded.logDescription.arr));
        REQUIRE(log_asn.logIndex == log_decoded.logIndex);
    }

    SECTION("LogIntValueASN"){
        std::string msg = " int msg";
        uint32_t log_index = 3;
        std::string log_str_value = "msg value";

        auto log_asn = get_LogStringValueASN(msg, log_str_value, log_index);

        // encode
        auto log_encoded = encode_LogASN(log_asn);

        // decode
        auto log_decoded = decode_LogASN(log_encoded);

        REQUIRE(log_asn.logChoice.kind == log_decoded.logChoice.kind);
        REQUIRE(strcpy((char*)log_asn.logDescription.arr, (char*)log_decoded.logDescription.arr));
        REQUIRE(log_asn.logIndex == log_decoded.logIndex);
        REQUIRE(log_asn.logChoice.u.logIntValue.intValue == log_decoded.logChoice.u.logIntValue.intValue);
    }

    SECTION("LogStringValueASN"){
        std::string msg = " int msg";
        uint32_t log_index = 3;
        std::string log_str_value = "msg value";

        auto log_asn = get_LogStringValueASN(msg, log_str_value, log_index);

        // encode
        auto log_encoded = encode_LogASN(log_asn);

        // decode
        auto log_decoded = decode_LogASN(log_encoded);

        REQUIRE(log_asn.logChoice.kind == log_decoded.logChoice.kind);
        REQUIRE(strcpy((char*)log_asn.logDescription.arr, (char*)log_decoded.logDescription.arr));
        REQUIRE(log_asn.logIndex == log_decoded.logIndex);
        REQUIRE(strcpy((char*)log_asn.logChoice.u.logStringValue.stringValue.arr, (char*)log_decoded.logChoice.u.logStringValue.stringValue.arr));

    }
}