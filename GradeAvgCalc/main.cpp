#include <iostream>
#include <fstream>
#include <iomanip>

using std:: cout;
using std:: cin;
using std:: string;
using std:: endl;
using std:: setw;

double print_grades(double values[], int max_points);
double calculate_letter(double final_grade);

int main() {
	string input_file;
	int i = 0;
	int x = 0;
	int count = 0;
	int points = 0;
	int max_points = 0;
	double values[30] = {0};
	double final_grade;
	
  cout << "Enter the input file: "; getline(cin, input_file);
	cout << "\n";

	for (int x = 0; x < 30; x++){
		values[x] = -1;
	}
	std:: ifstream grades;
	grades.open(input_file);
	
	while (grades){
		for (i = 0; i < 30; i++){
			grades >> values[i];
		}
	}
	for (int y = 0; y < 30; y++){
		if (values[y] != -1){
			points = points + values[y];
			max_points = max_points + 100;
			count += 1;
		}
	}
	
	cout << "Number of Grades: " << setw(10) << count << endl;
	cout << "Total Points Earned:  " << setw(6) << points << endl;
	cout << "Max Possible Points:  " << setw(6) << max_points << endl;

	final_grade = print_grades(values, max_points);
	calculate_letter(final_grade);

	grades.close();
}

double print_grades(double values[], int count){
	int i = 0;
	double percentage = 0;
	double final_grade = 0;

	cout << "\n";
	for (i = 0; i < 30; i++){
		if (values[i] != -1){
			//cout << std:: fixed << std:: setprecision(1);
			percentage = ((values[i] / count) * 100);
			cout << std:: fixed << std:: setprecision(1);
			cout << setw(19) << values[i] << "    ";
			cout << setw(4) << percentage << "%" << endl;
			final_grade = final_grade + percentage;
		}
	}
	
	return final_grade;
}

double calculate_letter(double final_grade){
	string grade;
	if (final_grade >= 90){
		grade = "A";
	}
	else if (final_grade < 90 && final_grade >= 80){
		grade = "B";
	}
	else if (final_grade < 80 && final_grade >= 70){
		grade = "C";
	}
	else if (final_grade < 70 && final_grade >= 60){
		grade = "D";
	}
	else if (final_grade < 60){
		grade = "F";
	}

	if (final_grade == 0){
		cout << "\n" << "Final Grade:" << setw(7) << grade << "    " << setw(4) << final_grade << "%";
	}
	else {
		cout << "\n" << "Final Grade:" << setw(7) << grade << "    " << final_grade << "%";
	}
	return 0;
}
