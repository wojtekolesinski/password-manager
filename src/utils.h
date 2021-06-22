#ifndef PASSWORD_MANAGER_UTILS_H
#define PASSWORD_MANAGER_UTILS_H

namespace util {
    char* encode(char *password, int size);
    char* decode(char* password, int size);

    struct Node {
        int data;
        Node* next;
    };

    class List {
    public:
        List();
    private:
        Node* head;
    };
}
#endif //PASSWORD_MANAGER_UTILS_H
