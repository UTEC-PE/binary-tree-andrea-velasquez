#ifndef NODE_H
#define NODE_H

#include <string>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr){};
    void killSelf();
};

#endif
