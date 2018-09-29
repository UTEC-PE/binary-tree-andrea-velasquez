#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* left;
    Node<T>* right;

    Node(T data) : data(data), left(nullptr), right(nullptr){};
    void killSelf(){
      if (left) left->killSelf();
      if (right) right->killSelf();
      delete this;
    };
};


#endif
