/*
Project Purpose: Gaussian Elimination Implementation in C++
*/

#include <iostream>
using namespace std;

int main() {
	double divisor;
	double multiplier;
	
	//Matrix Creator
	const int num_row = 3;
	const int num_col = 4;
	double aug_matrix[num_row][num_col] = {{2,-3,1,-22},
										   {7,9,-3,14},
										   {6,7,2,91}};

	//Gaussian Elimination Algorithm
	for (int i = 0; i < num_row; i++){
		divisor = aug_matrix[i][i];
		for (int j = 0; j < num_col; j++){
			aug_matrix[i][j] /= divisor;
		}
		for (int j = 0; j < num_row; j++){
			if (j != i){
				multiplier = -aug_matrix[j][i];
				for (int k = 0; k < num_col; k++){
					aug_matrix[j][k] = aug_matrix[j][k] + multiplier*aug_matrix[i][k];
				}
			}
		}
	}


	//Print out the matrix after the algorithm
	for (int i = 0; i < num_row; i++){
		for (int j = 0; j < num_col; j++){
			cout << aug_matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0; 
}
