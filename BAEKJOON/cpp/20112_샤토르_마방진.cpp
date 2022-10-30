#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<char>> v;

void input() {
	cin >> n;

	v.assign(n, vector<char>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}
}

void solution() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] != v[j][i]) {
				cout << "NO";
				return;
			}
		}
	}

	cout << "YES";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}