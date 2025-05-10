#include <iostream>

using namespace std;

int main() {
	double x, y, ans;
	char op;

	cout << "Enter your first number: ", cin >> x;
	cout << endl;
	
	cout << "Enter operator (+, -, *, /): ", cin >> op;
	cout << endl;
	
	cout << "Enter your second number: ", cin >> y;
	cout << endl;

	if (op == '+'){
		ans = x + y;
	}
	else if (op == '-'){
		ans = x - y;
	}
	else if (op == '*'){
		ans = x * y;
	}
	else if (op == '/'){
		if (y == 0){
			cout << "Error: Cannot divide by 0" << endl;
			return 1;
		}
		ans = x / y;
	}
	else{
		cout << "Error: Invalid operator" << endl;
		return 1;
	}

	cout << "Result: " << x << " " << op << " " << y << " = " << ans << endl;
	
	return 0;
}
