/* Program Description:    
  This program creates a Concordance for a text file using a binary tree which updates frequency, words, and where the word occurs
*/ 

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>       
#include <vector>       
#include <algorithm>    
#include <cctype>       
#include "wordEntry.h"
#include "BST.h"
#include <iomanip>

using namespace std;

//Function Prototype
void Concordance(const string& line, int line_num, BST& Tree);

int main(){
	//Variables and Objects
  BST Con_tree;
	string file_data, line;
	int line_num = 0;
	ifstream myFile;

	cout << "This program will read a file and create a list of word frequency and line numbers." << "\n\n";
	//Asks user for file input
	cout << "Please enter the name of the file to read:	", cin >> file_data;
	cout << "\n\n";
	myFile.open(file_data);

	//If invalid file
	if (!myFile){
		cout << "Invalid File" << endl;
		return 0;
	}

	//Formatted Table for the concordance
	cout << "---------------- ------------ -----------------------------" << endl;
	cout << left << setw(20) << "Word" << setw(10) << "Frequency" <<	"Occurs on Lines" << endl;
	cout << "---------------- ------------ -----------------------------" << endl;

	//While loop for an entire line of the file
	while(getline(myFile, line)){
		//Increment the line number
		line_num++;
		//Call the Concordance Function to create the BST
		Concordance(line, line_num, Con_tree);
	}

	//Print out the BST in order
	Con_tree.inorder();

	cout << "\n\n";
	cout << "Thank you for using our program." << endl;
	
	//Close the File
	myFile.close();
	return 0;
}


//Concordance Function for BST
void Concordance(const string& line, int line_num, BST& Tree){
	//Makes each word in the line lowercase
	stringstream s(line);
	string word, word_fixed;

	//While loop for making each word lower
	while (s >> word){
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		//For loop to see if each character in the word is a letter and not a punctuation mark
		for (int i = 0; i < word.length(); i++){
			char x = word[i];
			//If its a letter then add it to the string
			if (isalpha(x)){
				word_fixed += x;
			}
		}

		//Object for wordEntry
		wordEntry word_ent;

		//Put all information into the struct
		word_ent.word = word_fixed;
		word_ent.frequency = 1;
		word_ent.line_nums.push_back(line_num);
		word_ent.last_line = line_num;

		//Inserts the struct into the BST class to start creating the Concordance BST
		Tree.insertItem_update(word_ent);
		//clears the word string for the next word
		word_fixed = "";
	}
}
