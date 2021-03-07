#include <iostream>
#include "fault_injection_messages_api.h"



int main() {
    InjectionConfiguration configuration = get_InjectionCollection(true,
                                                                   10,
                                                                   2);
    auto bytes = encode_InjectionConfiguration(configuration);

    InjectionConfiguration configuration2 = decode_InjectionConfiguration(bytes);


    std::cout << "We are on a mission from God!" << std::endl;
    return 0;
}
