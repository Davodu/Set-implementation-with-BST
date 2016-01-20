#include <iostream>
#include "bstset.h"

int main() {
  BstSet<int> *bst  = new BstSet<int> () ;
  bst -> add (8);
  bst -> add (6);
  bst -> add (14);
  bst -> add (11);
  bst -> add (9);
  bst -> add (7);
  bst -> remove (11);
  try{
    bst -> contains (11);
  }
  catch (std:: invalid_argument &ia) {
    std:: cout<< "cant find it "<< std::endl;
  }
  bst->printtree();
  delete bst;
}
