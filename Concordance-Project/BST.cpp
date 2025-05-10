#include "BST.h"
#include "wordEntry.h"
#include <iostream>
#include <iomanip>

using namespace std;

//Constructor
BST::BST(){
	root = nullptr;
}


//Destructor
BST::~BST(){}


//Function to both insert the word and update the BST for any duplicate word
void BST::insertItem_update(const wordEntry& data){
	//If the root is empty
	if (!root){
		root = new Tree(data, nullptr, nullptr);
	}

	//make a traversal node for the tree
	Tree* current = root;

	//While loop to insert the words into the BST
	while(current != nullptr){
		//If there is a duplicate word in the BST
		if (data.Key() == current->data.Key()){
			current->data.frequency += data.frequency;

			//Loop to find if the line numbers are duplicate also
			bool dup_line = false;
			list<int>::iterator it;
			for (it = current->data.line_nums.begin(); it != current->data.line_nums.end(); it++){
				if (*it == data.last_line){
					dup_line = true;
				}
			}

			//If the line numbers are not the same then add to the list
			if (!dup_line){
				current->data.last_line = data.last_line;
				current->data.line_nums.push_back(data.last_line);
			}
			//If the line numbers are the same then move on to the next line number
			else{
				current->data.last_line = data.last_line;
			}
			return;
		}
		//If the word being inserted or updated is less than the current node
		else if (data.Key() < current->data.Key()){
			//Make and add a new node to the left subtree of the root
			if(!current->left){
				current->left = new Tree(data, nullptr, nullptr);
				return;
			}
			//Move current to the left
			current = current->left;
		}
		//If the word being inserted or updated is greater than the current node
		else if (data.Key() > current->data.Key()){
			//Make and add a new node to the right subtree of the root
			if (!current->right){
				current->right = new Tree(data, nullptr, nullptr);
				return;
			}
			//Move current to the right
			current = current->right;
		}
	}
}

//Calls the inorder print traversal function for the root
void BST::inorder(){
	inorder(root);
}


//Prints out the concordance in order recursively
void BST::inorder(Tree* treeptr){
	//If the tree is empty then return
	if(treeptr == nullptr){
		return;
	}
	
	//Recursive call inorder for the left subtree 
	inorder(treeptr->left);
	
	//Printing out the word and frequency
	cout << setw(28) << left << treeptr->data.word
			 << setw(7) << treeptr->data.frequency;
	
	//For loop to print out the line numbers
	list<int>::iterator it;
	for (it = treeptr->data.line_nums.begin(); it != treeptr->data.line_nums.end(); ++it){
		if (it == treeptr->data.line_nums.begin()){
			cout << *it;
		}
		else{
			cout << ", " << *it;
		}
	}
	cout << endl;
	
	//Recursive call inorder for the right subtree
	inorder(treeptr->right);
}
