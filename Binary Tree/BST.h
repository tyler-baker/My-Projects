#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
using namespace std;

// Stack template
template <class T>
class BinaryTree
{
private:
   struct TreeNode
   {
      T value;           // The value in the node
      TreeNode *left;    // Pointer to left child node
      TreeNode *right;   // Pointer to right child node
   };

   TreeNode *root;       // Pointer to the root node
   
   // Private member functions
   void insert(TreeNode *&, TreeNode *&);
   void destroySubTree(TreeNode *);
   void deleteNode(T, TreeNode *&);
   void makeDeletion(TreeNode *&);
   void displayInOrder(TreeNode *) const;
   void displayPreOrder(TreeNode *) const;
   void displayPostOrder(TreeNode *) const;
   int numNodes(TreeNode *node) const;
	 int numLeafNodes(TreeNode *node) const;
	 int getHeight(TreeNode *node) const;
	 int level(TreeNode *node, T, int levelCounter) const;
	 bool displayAncestors(T, TreeNode *nodeRoot) const;

public:
   // Constructor
   BinaryTree()
      { root = nullptr; }
      
   // Destructor
   ~BinaryTree()
      { destroySubTree(root); }
      
   // Binary tree operations
   void insertNode(T);
   bool searchNode(T);
   void remove(T);
   bool empty() const;
   int numNodes() const;
	 int numLeafNodes() const;
	 int getHeight() const;
	 int level(T) const;
	 bool displayAncestors(T);


   void displayInOrder() const
      {  displayInOrder(root); }
      
   void displayPreOrder() const
      {  displayPreOrder(root); }
      
   void displayPostOrder() const
      {  displayPostOrder(root); }
};

//*************************************************************
// insert accepts a TreeNode pointer and a pointer to a node. *
// The function inserts the node into the tree pointed to by  *
// the TreeNode pointer. This function is called recursively. *
//*************************************************************
template <class T>
void BinaryTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
   if (nodePtr == nullptr)
      nodePtr = newNode;                  // Insert the node.
   else if (newNode->value < nodePtr->value)
      insert(nodePtr->left, newNode);     // Search the left branch
   else 
      insert(nodePtr->right, newNode);    // Search the right branch
}

//**********************************************************
// insertNode creates a new node to hold num as its value, *
// and passes it to the insert function.                   *
//**********************************************************
template <class T>
void BinaryTree<T>::insertNode(T item)
{
   TreeNode *newNode = nullptr;	// Pointer to a new node.

   // Create a new node and store num in it.
   newNode = new TreeNode;
   newNode->value = item;
   newNode->left = newNode->right = nullptr;
   
   // Insert the node.
   insert(root, newNode);
}

//***************************************************
// destroySubTree is called by the destructor. It   *
// deletes all nodes in the tree.                   *
//***************************************************
template <class T>
void BinaryTree<T>::destroySubTree(TreeNode *nodePtr)
{
   if (nodePtr)
   {
      if (nodePtr->left)
         destroySubTree(nodePtr->left);
      if (nodePtr->right)
         destroySubTree(nodePtr->right);
      delete nodePtr;
   }
}
   
//***************************************************
// searchNode determines if a value is present in   *
// the tree. If so, the function returns true.      *
// Otherwise, it returns false.                     *
//***************************************************
template <class T>
bool BinaryTree<T>::searchNode(T item)
{
   TreeNode *nodePtr = root;

   while (nodePtr)
   {
      if (nodePtr->value == item)
         return true;
      else if (item < nodePtr->value)
         nodePtr = nodePtr->left;
      else
         nodePtr = nodePtr->right;
   }
   return false;
}

//**********************************************
// remove calls deleteNode to delete the       *
// node whose value member is the same as num. *
//**********************************************
template <class T>
void BinaryTree<T>::remove(T item)
{
   deleteNode(item, root);
}

//********************************************
// deleteNode deletes the node whose value   *
// member is the same as num.                *
//********************************************
template <class T>
void BinaryTree<T>::deleteNode(T item, TreeNode *&nodePtr)
{
   if (item < nodePtr->value)
      deleteNode(item, nodePtr->left);
   else if (item > nodePtr->value)
      deleteNode(item, nodePtr->right);
   else
      makeDeletion(nodePtr);
}

//***********************************************************
// makeDeletion takes a reference to a pointer to the node  *
// that is to be deleted. The node is removed and the       *
// branches of the tree below the node are reattached.      *
//***********************************************************
template <class T>
void BinaryTree<T>::makeDeletion(TreeNode *&nodePtr)
{
   // Define a temporary pointer to use in reattaching
   // the left subtree.
   TreeNode *tempNodePtr = nullptr;

   if (nodePtr == nullptr)
      cout << "Cannot delete empty node.\n";
   else if (nodePtr->right == nullptr)
   {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->left;   // Reattach the left child
      delete tempNodePtr;
   }
   else if (nodePtr->left == nullptr)
   {
      tempNodePtr = nodePtr;
      nodePtr = nodePtr->right;  // Reattach the right child
      delete tempNodePtr;
   }
   // If the node has two children.
   else
   {
      // Move one node the right.
      tempNodePtr = nodePtr->right;
      // Go to the end left node.
      while (tempNodePtr->left)
         tempNodePtr = tempNodePtr->left;
      // Reattach the left subtree.
      tempNodePtr->left = nodePtr->left;
      tempNodePtr = nodePtr;
      // Reattach the right subtree.
      nodePtr = nodePtr->right;
      delete tempNodePtr;
   }
}

//****************************************************************
// The displayInOrder member function displays the values        *
// in the subtree pointed to by nodePtr, via inorder traversal.  *
//****************************************************************
template <class T>
void BinaryTree<T>::displayInOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
      displayInOrder(nodePtr->left);
      cout << nodePtr->value << endl;
      displayInOrder(nodePtr->right);
   }
}

//****************************************************************
// The displayPreOrder member function displays the values       *
// in the subtree pointed to by nodePtr, via preorder traversal. *
//****************************************************************
template <class T>
void BinaryTree<T>::displayPreOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
      cout << nodePtr->value << endl;
      displayPreOrder(nodePtr->left);     
      displayPreOrder(nodePtr->right);
   }
}

//****************************************************************
// The displayPostOrder member function displays the values      *
// in the subtree pointed to by nodePtr, via postorder traversal.*
//****************************************************************
template <class T>
void BinaryTree<T>::displayPostOrder(TreeNode *nodePtr) const
{
   if (nodePtr)
   {
      displayPostOrder(nodePtr->left);    
      displayPostOrder(nodePtr->right);
      cout << nodePtr->value << endl;
   }
}

//========================= bool Empty ===========================
// The empty function checks the root node of the tree to see if *
// the tree is empty. It returns true if root is nullptr         *
//================================================================
template <class T>
bool BinaryTree<T>::empty() const
{
  return root == nullptr;

}

//======================== int numNodes =========================
// The numNodes function traverses through the tree and counts  *
// the number of nodes. This functoin uses recursion.           *
//===============================================================
template <class T>
int BinaryTree<T>::numNodes() const
{
	int c = 1;
	
	if(empty())
  	return 0;

	else{
		c += numNodes(root->left);
		c += numNodes(root->right);
  	return c;
	}
}

//======================== int numNodes =========================
// The private helper version of numNodes takes a tree node     *
// pointer as a parameter, this function allows the public      *
// version to use recursion to count the number of nodes.       *
//===============================================================
template <class T>
int BinaryTree<T>::numNodes(TreeNode *node) const
{
	int c = 1;
	if(node == nullptr)
	  return 0;
	else{
		c += numNodes(node->left);
		c += numNodes(node->right);
		return c;
	}

}

//====================== int numLeafNodes =======================
// The numLeafNodes function traverses through the tree and     *
// counts the number of leaf nodes found in the tree. This      *
// function uses recursoin.                                     *
//===============================================================
template <class T>
int BinaryTree<T>::numLeafNodes() const
{
	int c = 0;

	if(empty())
		return 0;
	
	if(root->left == nullptr && root->right == nullptr)
		return 1;
	else{
		c += numLeafNodes(root->left);
		c += numLeafNodes(root->right);
		return c;
	}
}

//====================== int numLeafNodes ========================
// The private helper version of numNodes takes a tree node      *
// pointer as a parameter, this function allows the public       *
// version to use recursion to count the number of  leaf nodes.  *
//================================================================
template <class T>
int BinaryTree<T>::numLeafNodes(TreeNode *node) const
{
	int c = 0;
	if(node == nullptr)
		return 0;
	if(node->left == nullptr && node->right == nullptr)
		return 1;
	else{
		c += numLeafNodes(node->left);
		c += numLeafNodes(node->right);
		return c;
	}
}

//======================== int getHeight =========================
// The getHeight function traverses through the tree and locates *
// the longest path from root to a leaf node using recursion.    *
//================================================================
template <class T>
int BinaryTree<T>::getHeight() const
{
		if(empty())
			return 0;
		return 1 + max(getHeight(root->left), getHeight(root->right));
}

//======================== int getHeight =========================
// The private helper version of getHeight takes a tree node     *
// pointer as a parameter, this function allows the public       *
// version to use recursion to locate the longest path from root *
// to a leaf node.                                               *
//================================================================
template <class T>
int BinaryTree<T>::getHeight(TreeNode *node) const
{
	if(node == nullptr)
		return 0;
	return 1 + max(getHeight(node->left), getHeight(node->right));	
}

//======================== int level =============================
// The level function takes in a value of the same type as the   *
// tree, locates the node if it exists within the tree, then     *
// returns the level it is on using recursion                    *
//================================================================
template <class T>
int BinaryTree<T>::level(T data) const
{
	int levelCounter = 1;
	int downLevel;

	if(empty())
		return 0;
	
	if(root->value == data)
		return levelCounter;
	
	downLevel = level(root->left, data, levelCounter + 1);
	if(downLevel != 0)
		return downLevel;
	
	downLevel = level(root->right, data, levelCounter + 1);
	if(downLevel == 0)
		return -1;
	else
		return downLevel;
	
}

//======================== int level =============================
// The private helper version of level takes in a tree node      *
// pointer, a value of the same type as the tree, and the level  *
// counter passed from the public version to allow the public    *
// version to use recursion to calculate the level on which the  *
// node is found.                                                *
//================================================================
template <class T>
int BinaryTree<T>::level(TreeNode *node, T data, int levelCounter) const
{
	int downLevel;
	if(node == nullptr)
		return 0;
	
	if(node->value == data)
		return levelCounter;

	downLevel = level(node->left, data, levelCounter + 1);
	if(downLevel != 0)
		return downLevel;

	downLevel = level(node->right, data, levelCounter + 1);
	return downLevel;

}

//===================== bool displayAncestors ====================
// The display ancestors function takes in a value matching the  *
// type of the tree, it then locates the node if it exists and   *
// prints out all of the nodes between (and including) root and  *
// the node. This function returns a boolean value indicating    *
// whether the node has any nodes above it in the tree, it will  *
// if the node exists the function will only retrun false if the *
// node is the root node.                                        *
//================================================================
template <class T>
bool BinaryTree<T>::displayAncestors(T target)
{

	if(root == nullptr)
		return false;

	if(!searchNode(target)){
		cout << target << " is not in the tree. ";
		return false;
	}
	else{

		if(root->value == target)
			return true;
	
		if( displayAncestors(target, root->left) || 
				displayAncestors(target, root->right))
		{
			cout << root->value << " ";
			return true;
		}
	return false;
	}
}

//===================== bool displayAncestors ====================
// The private version of displayAncestors takes in a value      *
// matching the type of the tree as well as a node, this         *
// function allows the public version of displayAncestors to     *
// use recursion to "walk up" the tree in order to print the     *
// ancestors. This function returns a boolean value in the same  *
// way as it's public counterpart.                               *
//================================================================

template <class T>
bool BinaryTree<T>::displayAncestors(T target, TreeNode *rootNode) const
{
	if(rootNode == nullptr)
		return false;	
	if(rootNode->value == target)
		return true;
	if( displayAncestors(target, rootNode->left) ||
		  displayAncestors(target, rootNode->right))
	{
		cout << rootNode->value << " ";
		return true;
	}
	return false;
	
}

#endif
