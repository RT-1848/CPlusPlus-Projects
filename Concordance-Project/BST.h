#ifndef BST_H
#define BST_H

#include "wordEntry.h"
#include <iostream>

using namespace std;

//BST Class
class BST {
private:
	//Struct for the binary tree nodes
	struct Tree{
		wordEntry data;
		Tree *left;
		Tree *right;

		Tree(const wordEntry& data, Tree* l, Tree* r) : data(data), left(l), right(r) {}
	};

	//Root for the BST
	Tree *root;

	//Function to print the BST inorder
	void inorder(Tree* treeptr);

public:
	//BST Constructor and Destructor
	BST();
	~BST();

	//BST Function for Inserting and Updating the BST
	void insertItem_update(const wordEntry& data);
	//BST Function for Printing inorder
	void inorder();
};

#endif
