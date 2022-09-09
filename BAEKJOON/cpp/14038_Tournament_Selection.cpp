#include <iostream>
#include <vector>
using namespace std;

vector<char> v;

void input() {
	char c;

	for (int i = 0; i < 6; i++) {
		cin >> c;
		v.push_back(c);
	}
}

void solution() {
	int sum = 0;

	for (int i = 0; i < 6; i++) {
		if (v[i] == 'W') {
			sum++;
		}
	}

	if (sum >= 5) {
		cout << "1";
	}
	else if (sum >= 3) {
		cout << "2";
	}
	else if (sum >= 1) {
		cout << "3";
	}
	else {
		cout << "-1";
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