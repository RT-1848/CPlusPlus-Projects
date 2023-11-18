/* 
 Program Description:    
  This program implements four different functions
	1. The Fibonacci Sequence
 	2. A Recursive Sum Function
	3. A Recursive Function to find out the largest value in an array
 	4. A Recursive Function that finds the amount of eagles in a grid
*/ 

#include <iostream>
#include <fstream>
#include "parameters.h"

using namespace std;

int fibonacci(int FibValue);
int Sum(int SumValue);
int Largest(const int LarValue[], int num, int max_size);
int FindEagles(int grid[50][50], int row, int col);

int main() {
	//Fibonacci Sequence
	cout << "The Fibonacci Sequence from 1-" << FibVal << " are: ";
	for (int i = 0; i < FibVal; i++){
		cout << fibonacci(i) << " ";
	}
	cout << "\n\n";

	//Sum Sequence
	cout << "The Sum of integers from 1-" << SumVal << " is: ";
	cout << Sum(SumVal);
	cout << "\n\n";

	//Largest Value finder using recursion
	int num = 0;
	int max_size = 20;
	cout << "The Largest integer from the array of positive and negative values is: ";
	cout << Largest(LargestVal, num, max_size);
	cout << "\n\n";

	//Function to find the amount of eagles in a 2-D array
	ifstream myfile;
	int row, col, grid[50][50];
	myfile.open("eagle.dat");

	//Print out the grid
	while (myfile >> row >> col){
		for (int x = 0; x < row; x++){
			for (int y = 0; y < col; y++){
				myfile >> grid[x][y];
				cout << grid[x][y] << " ";
			}
			cout << endl;
		}
		//Count the eagles
		int eagles = 0;
		for (int i = 0; i < row; i++){
			for (int s = 0; s < col; s++){
				if (grid[i][s] != 0){
					int size = FindEagles(grid, i, s);
					cout << "\n" << "An eagle size " << size << " is found.";
					eagles++;
				}
			}
		}
		cout << "\n\n";
		cout << eagles << " eagle(s) found in the picture." << endl;
		cout << "\n";
	}

	myfile.close();
	
	return 0;
}

//Fibonacci Sequence recursive function
int fibonacci(int FibValue){
	if (FibValue == 0){
		return 0;
	}
	else if (FibValue == 1){
		return 1;
	}
	else {
		return (fibonacci(FibValue - 2) + fibonacci(FibValue - 1));
	}
}

//Sum of all integers Recursive Function
int Sum(int SumValue){
	if (SumValue == 0){
		return SumValue;
	}
	else{
		return SumValue + Sum(SumValue - 1);
	}
}

//Largest integer in the Array Recursive Function
int Largest(const int LarValue[], int num, int max_size){
	if (max_size == 0){
		return num;
	}
	else {
		if (LarValue[max_size-1] > num){
			num = LarValue[max_size-1];
		}
		return Largest(LarValue, num, max_size-1);
	}
}

//Find the Eagles in the array Recursive Function
int FindEagles(int grid[50][50], int row, int col){
	if (row < 0 || col < 0 || grid[row][col] == 0){
		return 0;
	}
	else{
		int count = 1;
		grid[row][col] = 0;
		for (int x = row - 1; x <= row + 1; x++){
			for (int y = col - 1; y <= col + 1; y++){
				count += FindEagles(grid, x, y);
			}
		}
		return count;
	}
}
