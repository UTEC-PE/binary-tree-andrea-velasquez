#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <stack>

using namespace std;
template <typename T>
class Iterator {
private:
  stack<Node<T>*> thestack;
  Node<T>* current;
  Node<T>* previous;

public:
  Iterator(Node<T>* root): current(root), previous(nullptr){
    thestack.push(current);
    while (current->left) {
      current=current->left;
      thestack.push(current);
    }
  };

  Iterator<T> operator++(){
    if (!current) throw "Iterator reach it's end";
    //go up
    if (!(current->left || current->right) ||
        (current->left && current->right && previous==current->right) ||
        (!current->right && current->left && previous==current->left) ||
        previous==current->right){
      do{
        previous = thestack.top();
        thestack.pop();
        if (thestack.empty()) {cout<<"Is empty\n"; current=nullptr; return *this;}
        current = thestack.top();
      }
      while (previous==current->right);
      return *this;
    }

    //go left
    if (current->left && previous!=current->left){
      current = current->left;
      thestack.push(current);
      return *this;
    }

    //go right
    if (current->right && previous!=current->right){
      current = current->right;
      thestack.push(current);
      while (current->left) {
        current=current->left;
        thestack.push(current);
      }
        return *this;
    }
    current=nullptr;
    return *this;
  };

  T operator*(){
    if (!current) throw "Can't get data of nullptr";
    return current->data;
  };
};


#endif
