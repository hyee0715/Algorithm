#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n;
vector<string> v1, v2;

void input() {
	string s;
	if (n % 2 == 0) {
		for (int i = 0; i < n / 2; i++) {
			cin >> s;
			v1.push_back(s);
		}

		for (int i = n / 2; i < n; i++) {
			cin >> s;
			v2.push_back(s);
		}
	}
	else {
		for (int i = 0; i < (n / 2) + 1; i++) {
			cin >> s;
			v1.push_back(s);
		}

		for (int i = (n / 2) + 1; i < n; i++) {
			cin >> s;
			v2.push_back(s);
		}
	}
}

void solutionf() {
	if (n % 2 == 0) {
		for (int i = 0; i < v1.size(); i++) {
			cout << v1[i] << "\n";
			cout << v2[i] << "\n";
		}
	}
	else {
		for (int i = 0; i < v2.size(); i++) {
			cout << v1[i] << "\n";
			cout << v2[i] << "\n";
		}

		cout << v1[v1.size() - 1] << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> n;

		if (n == 0) break;

		v1.clear();
		v2.clear();

		input();
		solutionf();
	}

	return 0;
}