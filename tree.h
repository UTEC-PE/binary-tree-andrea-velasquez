#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "node.h"
#include "iterator.h"


using namespace std;
template <class T>
class Tree{
private:
  Node<T>* root;
  int nodes=0;
  bool insert( Node<T>* currentroot, T element);
  void print_with_method(Node<T>* currentroot, int method);
public:
  Tree() : root(nullptr){};
  bool insert(T element);
  //bool remove(int element);
  void print_with_method(int method); //0 pre order, 1 in order, 2 post order
  int size() { return nodes; }

  void remove(int method);
  Iterator<T> begin(){
    Iterator<T> it(root);
    return it;
  };
  Iterator<T> end(){
    Iterator<T> it(nullptr);
    return it;
  };

  ~Tree(){
    if (root) root->killSelf();
    root=nullptr;
  }


  void print(){ print2D(root);};
};

// ---------------
template <typename T>
bool Tree<T>::insert(Node<T>* currentroot, T element){
  if (currentroot->data == element) { currentroot = new Node<T>(element); return false; }

   if (element<currentroot->data){
     if (currentroot->left) return insert(currentroot->left, element);
     else {  currentroot->left = new Node<T>(element); return true; }
   }
   else{
    if (currentroot->right) return insert(currentroot->right, element);
    else { currentroot->right = new Node<T>(element); return true; }
   }
}

template <typename T>
bool Tree<T>::insert(T element){
  //empty
  if (!root){ root=new Node<T>(element); ++nodes; return true; }
  bool ans = insert(root, element);
  if (ans) ++nodes;
  return ans;
}


// ---------------
template <typename T>
void Tree<T>::print_with_method(Node<T>* currentroot, int method){
  if (method==0) cout << (currentroot->data) <<" ";
  if (currentroot->left) print_with_method(currentroot->left, method);
  if (method==1) cout << (currentroot->data) <<" ";
  if (currentroot->right) print_with_method(currentroot->right, method);
  if (method==2) cout << (currentroot->data) <<" ";
}

template <typename T>
void Tree<T>::print_with_method(int method){
  print_with_method(root, method);
}

#endif
