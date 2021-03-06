//set class 
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include "set.h"
//using namespace std;
template <typename K>
  class BstSet : public Set <K> {
 private:
    class BSTNode {
    public :
      K key;
      BSTNode * left;
      BSTNode * right ;
      BSTNode (): key(0),left(NULL), right (NULL) {}
      BSTNode (const K &k ): key (k), left (NULL), right (NULL){}
      ~BSTNode () {}
    };
    BSTNode * root ;
 public :
 BstSet(): root (NULL) {}
    BSTNode * destroy (BSTNode * curr) {
      if (curr!= NULL){
	if (curr->left == NULL && curr->right ==NULL){
	  delete curr;
	  return NULL;
	}
	curr->left = destroy(curr->left);
	curr->right = destroy(curr->right);
	if (curr->left == NULL && curr->right == NULL) {
	  delete curr;
	  return NULL;
	}
	return curr;
      }
      else {
	return curr;
      }
    }
    
    virtual ~BstSet () {
      root = destroy(root);
    }
    
    virtual void add (const K & key){
      BSTNode * b = new BSTNode(key);
      BSTNode ** ptr = &root;
      int exist =0;
      while (*ptr!=NULL){
	if (key<(*ptr)->key){
	  ptr = & (*ptr) ->left;
	}
	else if (key > (*ptr)->key){
	  ptr = & (*ptr) ->right; 
	}
	else if (key ==(*ptr)->key) {
	  delete b;
	  exist=1;
	  break;
	}
      }
      if (!exist){
	*ptr = b;
      }
    }


    virtual bool contains (const K & key ) const {
      BSTNode * curr = root;
      while (curr!=NULL){
	if (curr->key == key){
	  return true;
	}
	if (key<curr->key){
	  curr=curr->left;
	}
	else {
	  curr = curr->right;
	} 
      }
      return false;
    }

    BSTNode * twoChildRm (BSTNode * curr , BSTNode * replace){
      if (curr->right ==NULL){
	replace ->key = curr ->key ;
	BSTNode * temp = curr->left;
	delete curr;
	return temp;
      }
      curr->right = twoChildRm (curr->right,replace);
      return curr;
    }

    BSTNode * remove (BSTNode * curr , K k){
      if (curr==NULL){
	return NULL;
      }
      BSTNode * temp;
      if (curr->key = k){
	if (curr->left == NULL){
	  temp = curr->right;
	  delete curr;
	  return temp;
	}
	if (curr->right == NULL){
          temp = curr->left;
          delete curr;
          return temp;
        }
	curr->left = twoChildRm(curr->left , curr);
	return curr;
      }
      else if (k<curr->key){
	curr->left = remove (curr->left, k);
      }
      else {
	curr->right = remove (curr->right, k);
      }
      return curr;
    }

    virtual void remove (const K & key) {
      root = remove (root, key);
    }
    void printtree () {
      printsub(root);
    }
    void printsub(BSTNode* curr) {
      if (curr!=NULL){
	std::cout << curr->key <<std::endl;
	printsub(curr->left);
	printsub(curr->right);
      }
    }

};
