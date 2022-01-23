#include <iostream>
using namespace std;

int n;

void input() {
	cin >> n;
}

void solution() {
	if (n >= 90) {
		cout << "A";
	}
	else if (n >= 80) {
		cout << "B";
	}
	else if (n >= 70) {
		cout << "C";
	}
	else if (n >= 60) {
		cout << "D";
	}
	else {
		cout << "F";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}