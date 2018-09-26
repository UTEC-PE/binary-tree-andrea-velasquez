#include <iostream>
#include "tree.h"
using namespace std;

int main(int argc, char *argv[]){

  Tree binarytree;

  for (int i=0; i<10; i++) binarytree.insert(rand() % 100);

  return EXIT_SUCCESS;
}
