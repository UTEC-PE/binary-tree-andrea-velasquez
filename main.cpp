#include <iostream>
#include<time.h>
#include<string>

#include "tree.h"

using namespace std;

int main(int argc, char *argv[]){
  Tree<int> binarytree;

  //string a[]={"hola", "me", "llamo", "programita", "soy", "feo"};
  srand(time(NULL));
  for (int i=0; i<6; i++) binarytree.insert(rand()%100);

  cout << "Pre order: ";
  binarytree.print_with_method(0);
  cout << "\nIn order: ";
  binarytree.print_with_method(1);
  cout << "\nPost order: ";
  binarytree.print_with_method(2);

  auto it = binarytree.begin();
  cout<<endl;
  for (; it!=binarytree.end(); ++it){
    cout << *it << " ";
  }

  return EXIT_SUCCESS;
}
