//Tyler Baker
// 5.6.15
// p2.cpp


#include <iostream>
#include "BST.h"
using namespace std;

const int WIDTH = 79;
const char SPACE = ' ';

void welcome();

int main()
{
	BinaryTree <int> BT;
	int target;

	welcome();

	
	BT.insertNode(90);
	BT.insertNode(50);
	BT.insertNode(150);
	BT.insertNode(20);
	BT.insertNode(75);
  BT.insertNode(95);
	BT.insertNode(80);
	BT.insertNode(92);
	BT.insertNode(111);
	BT.insertNode(4);
	
	cout << "90, 50,, 150, 20, 75, 95, 80, 92, 111, and 4 have been added"
			 << " to the tree" << endl;
	cout << "in that order.";
	
	cout << endl << endl;

	cout << "Tree in order: " << endl;
	cout << "-------------- " << endl << endl;
	BT.displayInOrder();

	cout << endl << endl;
	cout << "Press enter to continue...";
	cin.get();

	cout << endl << endl;
	
	cout << "Tree should not be empty, let's check: " << endl;
	if(BT.empty())
		cout << "Tree is empty.";
	else
		cout << "Tree is not empty.";
	cout << endl << endl;

	cout << "Enter another node, 10" << endl;
	BT.insertNode(10);
	cout << "Print the tree again with 10 included." << endl << endl;
	BT.displayInOrder();

	cout << endl << endl;
	cout << "Press enter to continue...";
	cin.get();

	cout << endl << endl;
	cout << "Is 111 in the tree?" << endl;
	if(BT.searchNode(111))
		cout << "111 is in the tree.";
	else
		cout << "111 is not in the tree.";
	
	cout << endl << endl;
	cout << "We will now remove the 10 node from the tree and display the "
			 << "tree." ;
	BT.remove(10);
	cout << endl << endl;
	BT.displayInOrder();

	cout << endl << endl;
	cout << "Display Pre Order: " << endl;
	BT.displayPreOrder();

	cout << endl << endl;
	cout << "Display Post Order: " << endl;
	BT.displayPostOrder();

	cout << endl << endl;
	cout << "Press enter to continue...";
	cin.get();

	cout << endl << endl;
	cout << "Number of Nodes: " << BT.numNodes();
  
	cout << endl << endl;
	cout << "Number of Leafs: " << BT.numLeafNodes();
	
	cout << endl << endl;
	cout << "Height of tree: " << BT.getHeight();
  
	cout << endl << endl;
	cout << "Enter a value to find the level of: ";
	cin >> target;
	if(BT.searchNode(target))
		cout << target << " is located at level " << BT.level(target) << ".";
	else
		cout << target << " is not in the tree.";

	cout << endl << endl;
	cout << "Enter a value to find the ancestors of: ";
	cin >> target;
	
	if(BT.displayAncestors(target))
		cout << "are the ancestors of " << target << ".";
	else
		cout << target << " does not have any ancestors.";
	
	cout << endl << endl;
  return 0;
}

void welcome()
{
	
	string msg = "Welcome to the binary searh tree test program.";
	int tempWidth;

	system("clear");

	for(int i = 0; i < 2; i++){
		for(int ii = 0; ii < WIDTH; ii++)
			cout << "-";
		cout << endl;
	}
	cout << endl;
	tempWidth = WIDTH - msg.length();
	
	for(int i = 0; i < tempWidth / 2; i++)
		cout << SPACE;
	cout << msg;
	for(int i = 0; i < tempWidth / 2; i++)
		cout << SPACE;
	cout << endl;
	for(int i = 0; i < 2; i++){
		for(int ii = 0; ii < WIDTH; ii++)
			cout << "-";
		cout << endl;
	}
}
