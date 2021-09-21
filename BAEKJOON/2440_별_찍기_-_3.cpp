#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = n; i >= 1; i--) {
		for (int j = n; j >= 1; j--) {
			if (i >= j) {
				cout << "*";
			}
		}
		cout << "\n";
	}

	return 0;
}