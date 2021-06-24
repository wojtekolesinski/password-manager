#pragma once
#include "Password.h"

namespace util {
    string encode(const string &password);
    string decode(const string &password);
    bool authenticate(string password, string input);
    string parseDelimited(string input, string delimiter, int index);

    struct Node {
        Password data;
        Node* next;
    };

    class List {
    public:
        List();
        void add(Password* data);
        void del(Password data);
        void del(int index);
        void show();
        void showFiltered(string filter);
    private:
        Node* head;
    };
}

