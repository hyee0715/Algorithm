#include <iostream>
#include <cmath>
using namespace std;

int arr[8];

void input() {
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}
}

bool is_ascending() {
	for (int i = 1; i < 8; i++) {
		if (arr[i - 1] - arr[i] != -1) {
			return false;
		}
	}
	return true;
}

bool is_descending() {
	for (int i = 1; i < 8; i++) {
		if (arr[i - 1] - arr[i] != 1) {
			return false;
		}
	}
	return true;
}

void solution() {
	if (is_ascending()) {
		cout << "ascending";
		return;
	}

	if (is_descending()) {
		cout << "descending";
		return;
	}

	cout << "mixed";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}