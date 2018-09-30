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
  bool find(Node<T>** &currentroot, T element);
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
    Iterator<T> it;
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
bool Tree<T>::find(Node<T>** &currentroot, T element){
  if ((*currentroot)->data == element) return true;

   if (element<(*currentroot)->data){
     if ((*currentroot)->left) { currentroot=&(*currentroot)->left; return find(currentroot, element); }
     else { currentroot=&(*currentroot)->left; return false; }
   }
   else{
    if ((*currentroot)->right) { currentroot=&(*currentroot)->right; return find(currentroot, element); }
    else { currentroot=&(*currentroot)->right; return false; }
   }
}

template <typename T>
bool Tree<T>::insert(T element){
  //empty
  if (!root){ root=new Node<T>(element); ++nodes; return true; }
  Node<T>** pointer = &root;
  if (!find(pointer, element)){
    *pointer = new Node<T>(element);
    ++nodes;
    return true;
  }
  return false;
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
