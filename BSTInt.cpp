
#include "BSTInt.h"

/* Function definitions for a int-based BST class */


/** Default destructor.
    Delete every node in this BST.
*/
BSTInt::~BSTInt() {
  deleteAll(root);
}

/** Given a reference to a Data item, insert a copy of it in this BST.
 *  Return  true if the item was added to this BST
 *  as a result of this call to insert,
 *  false if an item equal to this one was already in this BST.
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=)  For the reasoning
 *  behind this, see the assignment writeup.
 */

bool BSTInt::insert(int item)
{
  if (!root) {
    root = new BSTNodeInt(item);
    ++isize;
    //std::cout << item;
    return true;
  }

  BSTNodeInt* curr = root;
  
  //changed it to OR
  while (curr->left || curr->right) 
  {
    //checked if item is less
    if (item < curr->data) {
      if(curr->left) {
        curr = curr->left;
      }
      else {
        break;//break out of the loop
      }
    }
    
    //checked if it's more
    else if (curr->data < item) {
      if(curr->right) {
        curr = curr->right;
      }
      else {
        break;//break out of the loop
      }
    }
    else {
      return false;
    }
  }

  // Ready to insert
  BSTNodeInt* newNode = new BSTNodeInt(item);
  if (item < curr->data) {
    curr->left = newNode;
    newNode->parent = curr;
  }
  else if(item > curr->data) {
    curr->right = newNode;
    newNode->parent = curr;
  }
  else {
    return false;
  }

  ++isize;
  return true;

}


/** Find a Data item in the BST.
 *  Return true if the item is in the BST or false otherwise
 *  Note: This function should use only the '<' operator when comparing
 *  Data items. (should not use ==, >, <=, >=).  For the reasoning
 *  behind this, see the assignment writeup.
 */
bool BSTInt::find(int item) const
{
  BSTNodeInt* curr = root;
  while (curr) {
    if (curr->data < item) {
      curr = curr->right;
    }
    else if (item < curr->data) {
      curr = curr->left;
    }
    else {
      return true;
    }
  }
  return false;
}

  
/** Return the number of items currently in the BST.
 */
unsigned int BSTInt::size() const 
{
  return isize;
}

  
/** Return the height of the BST.
    Height of tree with just root node is 0
 */
int BSTInt::height() const
{
  return nodeHeight(root)-1;
  //call the helper method    
}

/**
 * Helper Method- nodeHeight(BSTNodeInt* root)
 * recursively goes through all the nodes in a tree
 * and calculates the height
 */
int BSTInt::nodeHeight(BSTNodeInt* root) const
{
  //check if root is null
  if(root == NULL)
  {
    return 0;
  } 
  
  //calculating the height of left side
  int height1 = nodeHeight(root -> left);
  
  //calculating the height of right side
  int height2 = nodeHeight(root -> right);
  
  //compare heights and return accordingly
  if(height1 > height2)
  {
    return height1 + 1;
  }
  
  else
  {
    return height2 + 1;
  }
}

/** Return true if the BST is empty, else false. 
 */
bool BSTInt::empty() const 
{

  if(root) 
  { 
    return false;//returns false when root is present
  } 
 
  return true;//else returns true

}




/** do a postorder traversal, deleting nodes
 * This is a helper for the destructor
 * This method is static because it acts on BSTNodeInts
 *   and not on the BSTInt object directly.
 */
void BSTInt::deleteAll(BSTNodeInt* n)
{
  if(n != NULL) { 
    deleteAll(n->left);
    deleteAll(n->right);
    delete n;
  }   
}
