#include <iostream>
#include <stack>
using namespace std;

int main() {
	int k;
	cin >> k;

	stack<int> s;
	int input;
	int sum = 0;

	for (int i = 0; i < k; i++) {
		cin >> input;

		if (input != 0) {
			s.push(input);
		}
		else {
			if (!s.empty()) {
				s.pop();
			}
		}
	}

	if (s.empty()) {
		cout << "0";
	}
	else {
		while (!s.empty()) {
			sum += s.top();
			s.pop();
		}
		
		cout << sum;
	}

	return 0;
}