#include <iostream>
#include "utils.h"

int main() {
    char password[] = "password123";

    util::encode(password, std::size(password));
    std::cout << password << std::endl;

    util::decode(password, std::size(password));
    std::cout << password << std::endl;
    return 0;
}
