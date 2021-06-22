#include "utils.h"



char* util::encode(char *password, int size) {
    for (int i = 0; i < size; i++) {
        password[i] += 26;
    }

    return password;
}

char* util::decode(char* password, int size) {
    for (int i = 0; i < size; i++) {
        password[i] -= 26;
    }

    return password;
}
