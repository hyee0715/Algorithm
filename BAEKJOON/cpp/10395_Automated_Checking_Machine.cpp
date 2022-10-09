#include <iostream>
#include <vector>
using namespace std;

vector<int> v1, v2;

void input() {
	int n;
	for (int i = 0; i < 5; i++) {
		cin >> n;
		v1.push_back(n);
	}

	for (int i = 0; i < 5; i++) {
		cin >> n;
		v2.push_back(n);
	}
}

void solution() {
	for (int i = 0; i < 5; i++) {
		if (v1[i] == 1) {
			if (v2[i] == 1) {
				cout << "N";
				return;
			}
		}
		else {
			if (v2[i] == 0) {
				cout << "N";
				return;
			}
		}
	}

	cout << "Y";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}