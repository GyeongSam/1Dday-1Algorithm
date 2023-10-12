#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	string exp;
	cin >> exp;
	vector <char> stack;

	for (char c : exp) {
		switch (c)
		{
		case '*':
			while (!stack.empty() && (stack.back() == '*' || stack.back() == '/')) {
				cout << stack.back();
				stack.pop_back();
			}
			stack.push_back(c);
			break;
		case '/':
			while (!stack.empty() && (stack.back() == '*' || stack.back() == '/')) {
					cout << stack.back();
					stack.pop_back();
			}
			stack.push_back(c);
			break;
		case '+':
			while (!stack.empty() && stack.back()!='(') {
				cout << stack.back();
				stack.pop_back();
			}
			stack.push_back(c);
			break;
		case '-':
			while (!stack.empty() && stack.back() != '(') {
				cout << stack.back();
				stack.pop_back();
			}
			stack.push_back(c);
			break;
		case '(':
			stack.push_back(c);
			break;
		case ')':
			while (stack.back() != '(') {
				cout << stack.back();
				stack.pop_back();
			}
			stack.pop_back();
			break;
		default:
			cout << c;
			break;
		}
	}
	while (!stack.empty()) {
		cout << stack.back();
		stack.pop_back();
	}
}