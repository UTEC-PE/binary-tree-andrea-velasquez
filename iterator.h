#ifdef ITERATOR_H
#define ITERATOR_H

#include "node.h"

template <typename T>
class Iterator {
private:
  stack<Node<T>*> the stack;
  Node<T>* current;
  Node<T>* previous;

public:
  Iterator(Node<T>* root): current(root), previous(nullptr){};

  Iterator<T> operator++(){
    if (current->left || current->right){
      Node<T>* currentrightorleft = nullptr;
      if (current->left!=previous) currentrightorleft = current->left;
      else if (current->right!=previous) currentrightorleft = current->right;

      //go left or right
      previous = current;
      current=currentrightorleft;
      thestack.push(current);
      return *this;

    }

    //go up
    previous = current;
    thestack.pop();
    current = thestack.top();
    return *this;
  };

};


#endif
