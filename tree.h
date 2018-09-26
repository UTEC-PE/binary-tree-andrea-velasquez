#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "node.h"

using namespace std;
class Tree{
private:
  Node* root;

  bool insert(Node* currentroot, int number){
    if (currentroot->data == number) return false;

     if (number<currentroot->data){
       if (currentroot->left) return insert(currentroot->left, number);
       else { currentroot->left=new Node(number); return true; }
     }
     else{
      if (currentroot->right) return insert(currentroot->right, number);
      else { currentroot->right=new Node(number); return true; }
     }
  };

public:
  Tree() : root(nullptr){};
  bool insert(int number){
    //empty
    if (!root){ root=new Node(number); return true; }

    return insert(root, number);
  };
  bool remove(int number);
};


#endif
