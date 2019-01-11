#ifndef BINARY_SEARCH_TREE_CLASS
#define BINARY_SEARCH_TREE_CLASS

#include <iostream>
#include <cstdlib>

#ifndef NULL
const int NULL = 0;
#endif  // NULL

#include "treenode.h"

template <class T>
class BinSTree {
  private:
    // pointer to tree root
    TreeNode<T> *root;

    // number of elements in the tree
    int size;

    // memory allocation/deallocation
    TreeNode<T>* GetTreeNode(const T& item, TreeNode<T> *lptr, TreeNode<T> *rptr);
    void FreeTreeNode(TreeNode<T> *p);

    // used by copy constructor and assignment operator
    TreeNode<T>* CopyTree(TreeNode<T> *t);

    // used by destructor and assignment operator
    void DeleteTree(TreeNode<T> *t);

  public:
    // locate a node with data item and its parent in tree.
    // used by Delete
    TreeNode<T>* FindNode(const T& item, TreeNode<T>* &parent) const;

    // constructors, destructor
    BinSTree(void);
    BinSTree(const BinSTree<T>& tree);
    ~BinSTree(void);

    // assignment operator
    BinSTree<T>& operator=(const BinSTree<T>& rhs);

    // tree handling methods
    void Insert(const T& item);
    void Delete(const T& item); // TO BE IMPLEMENTED IN PART 2
    int TreeEmpty(void) const;
    int TreeSize(void) const;
    void TreePrint(TreeNode<T>* parent);

    TreeNode<T>* GetRoot(void) const;
};

template <class T>
void BinSTree<T>::TreePrint(TreeNode<T>* parent) {
    if (parent != NULL) {
        TreePrint(parent->left);
        std::cout << parent->data << "-->";
        TreePrint(parent->right);
    }
}

// allocate a new tree node and return a pointer to it. Similar to GetNode of Linked List.
// DONE
template <class T>
TreeNode<T>* BinSTree<T>::GetTreeNode(const T& item,TreeNode<T> *lptr,TreeNode<T> *rptr) {
    TreeNode<T>* newNode;
    newNode = new TreeNode<T>(item, lptr, rptr);
    if (newNode == NULL) {
        std::cout << "failed GetTreeNode" << std::endl;
        exit(1);
    }
    return newNode;
}

// delete the storage occupied by a tree node
template <class T>
void BinSTree<T>::FreeTreeNode(TreeNode<T> *p) {
    if(p != NULL) {
        std::cout << "Memory for " << p->data << " is freed." << std::endl;
        delete p;
    } else
        std::cout << "Node pointer was NULL." << std::endl;

}

// RECURSIVELY copy tree t and make it the tree stored in the current object.
// DONE
template <class T>
TreeNode<T>* BinSTree<T>::CopyTree(TreeNode<T> *t) {
    TreeNode<T> *newlptr, *newrptr, *newNode;

    // if tree branch NULL, return NULL
    if (t == NULL)
        return NULL;

    // RECURSIVELY copy the left branch of root t and assign its root to newlptr
    newlptr = CopyTree(t->left);

    // RECURSIVELY copy the right branch of tree t and assign its root to newrptr
    newrptr = CopyTree(t->right);

    // allocate storage for the current root node and assign its data value
    // and pointers to its subtrees. return its pointer
    newNode = GetTreeNode(t->data, newlptr, newrptr);
    return newNode;
}

// delete the tree stored by the current object.
// DONE
template <class T>
void BinSTree<T>::DeleteTree(TreeNode<T> *t) {
    // if current root node is not NULL, delete its left subtree,
    // its right subtree and then the node itself
    if(t != NULL) {
        DeleteTree(t->left);
        DeleteTree(t->right);

        FreeTreeNode(t);
    }
}

// search for data item in the tree. if found, return its node
// address and a pointer to its parent; otherwise, return NULL.
// DONE
template <class T>
TreeNode<T> *BinSTree<T>::FindNode(const T& item, TreeNode<T>* &parent) const {
    TreeNode<T>* currNode = root;
    if (parent == NULL)
        return NULL; // return = NULL && parent = NULL
    else {
        while(currNode->data != item) {
            parent = currNode; // update parent to save the origin node
            if(currNode->data < item)
                currNode = currNode->right;
            else if (currNode->data > item)
                currNode = currNode->left;
        }
    }
    return currNode;
}

// constructor. initialize root to NULL, size to 0
template <class T>
BinSTree<T>::BinSTree(void): root(NULL), size(0) {

}

// copy constructor.
// DONE
template <class T>
BinSTree<T>::BinSTree(const BinSTree<T>& tree) {
    // copy tree to the current object. assign size
    if(root != NULL)
        root = CopyTree(tree.root);
    this->size = tree.size;

}

// destructor
// DONE
template <class T>
BinSTree<T>::~BinSTree(void) {
    DeleteTree(root);
}

// assignment operator.
// DONE
template <class T>
BinSTree<T>& BinSTree<T>::operator= (const BinSTree<T>& rhs) {
    // can't copy a tree to itself
    if (this == &rhs)
        return *this;

    // Delete current tree. copy new tree into current object
    DeleteTree(root);
    this->root = CopyTree(rhs.root);
    // set the tree size
    this->size = rhs.size;

    // return reference to current object
    return *this;
}

// insert item into the search tree
// DONE
template <class T>
void BinSTree<T>::Insert(const T& item) {
    // t is current node in traversal, parent the previous node
    TreeNode<T> *t = root, *parent = NULL, *newNode;

    // Search for the point of insertion by searching for the item in the tree.
    // Terminate on on empty subtree, insertion is at the leaf position.
    while(t != NULL) {
        if (item < t->data) {
            parent = t;
            t = t->left;
        } else if (item > t->data) {
            parent = t;
            t = t->right;
        } else
            break;
    }
    // create the new leaf node and insert. Special case: Insertion can be at the root node.
    if (root == NULL) {
        newNode = GetTreeNode(item, NULL, NULL);
        root = newNode;
    } else if (item < parent->data) {
        newNode = GetTreeNode(item, parent->left, NULL);
        parent->left = newNode;
    } else if (item > parent->data) {
        newNode = GetTreeNode(item, NULL, parent->right);
        parent->right = newNode;
    }

    // Update the state of the tree object
    size++;

}

// if item is in the tree, delete it. PART 2
// DONE
// NOTE THAT I BENEFITED FROM THE WEBSITE BELOW FOR THIS FUNCTION
// http://code.activestate.com/recipes/577552-binary-search-tree/
template <class T>
void BinSTree<T>::Delete(const T& item) {

    TreeNode<T> * parentPtr=root;
    TreeNode<T> * itemPtr=FindNode(item,parentPtr); //locate the node of the foo

    if(itemPtr) { //if it is not null then
        if(itemPtr->left != NULL && itemPtr->right != NULL) { //2 children case
            TreeNode<T> * itemPtrSuccessor=itemPtr;
            TreeNode<T> * parentPtrOfSuccessor=itemPtrSuccessor;
            itemPtrSuccessor=itemPtrSuccessor->left;

            while(itemPtrSuccessor->right != NULL) {
                parentPtrOfSuccessor=itemPtrSuccessor;
                itemPtrSuccessor=itemPtrSuccessor->right;
            }
            //std::cout << "itemPtr= "<< itemPtr->data <<std::endl;
            //std::cout <<"parentPtr= "<< parentPtr->data <<std::endl;
            // std::cout << "itemPtrSuccessor= "<< itemPtrSuccessor->data <<std::endl;

            //std::cout <<"parentPtrOfSuccessor= "<< parentPtrOfSuccessor->data <<std::endl;

            // remove the itemSuccessor from its parent
            if(parentPtrOfSuccessor->left == itemPtrSuccessor)
                parentPtrOfSuccessor->left = NULL;
            else
                parentPtrOfSuccessor->right = NULL;

            // update the child of parentPtr
            // if the removed itemPtr is not ROOT
            if(itemPtr != parentPtr) {
                            if(parentPtr->left == itemPtr)
                parentPtr->left = itemPtrSuccessor;
            else
                parentPtr->right = itemPtrSuccessor;
            }
            // if the removed itemPtr is  ROOT
            else {
                root = itemPtrSuccessor;
            }


            // update the children of the itemSuccessor
            itemPtrSuccessor->right = itemPtr->right;
            itemPtrSuccessor->left = itemPtr->left;



            // remove the itemPtr
            FreeTreeNode(itemPtr);
            size--;
            return;
        }

        // 1 or 0 child case
        // find if left or right is null
        TreeNode<T> *tmp ;
        if(itemPtr->left == NULL)
            tmp = itemPtr->right;
        else
            tmp = itemPtr->left;

        // update the child of the parent
        if(parentPtr == NULL)
            root=tmp;
        else if(parentPtr->data < itemPtr->data)
            parentPtr->right=tmp;
        else
            parentPtr->left=tmp;

        FreeTreeNode(itemPtr);
        size--;
        return;
    }
}

// indicate whether the tree is empty
template <class T>
int BinSTree<T>::TreeEmpty(void) const {
    return root == NULL;
}

// return the number of data items in the tree
template <class T>
int BinSTree<T>::TreeSize(void) const {
    return size;
}

// return the address of the root node.
template <class T>
TreeNode<T> *BinSTree<T>::GetRoot(void) const {
    return root;
}

#endif  // BINARY_SEARCH_TREE_CLASS
