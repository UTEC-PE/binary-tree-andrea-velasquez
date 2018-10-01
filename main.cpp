#include <iostream>
#include<time.h>
#include<string>

#include "tree.h"

using namespace std;

int main(int argc, char *argv[]){
  Tree<int> binarytree;

  int a[]={76, 1, 28, 89, 92, 90};
  srand(time(NULL));
  int num = 0;
  cout << "Input: ";
  for (int i=0; i<6; i++) {
    num = a[i];
    cout <<num <<", ";
    binarytree.insert(num);
  }

  cout << "\n\nPre order: ";
  binarytree.print_with_method(0);
  cout << "\nIn order: ";
  binarytree.print_with_method(1);
  cout << "\nPost order: ";
  binarytree.print_with_method(2);

  cout << "\n\nSize before remove: " <<binarytree.weight();

  int toremove = 76;
  cout <<"\nRemoving element " << toremove << "...";
  binarytree.remove(toremove);

  cout << "\nSize after remove: " <<binarytree.weight();

  cout << "\n\nHeight: " <<binarytree.getHeight();
  cout << "\n\nIterator in order: ";
  for (auto it = binarytree.begin(); it!=binarytree.end(); ++it){
    cout << *it << " ";
  }

  return EXIT_SUCCESS;
}
