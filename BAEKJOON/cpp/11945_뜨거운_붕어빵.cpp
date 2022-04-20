#include <iostream>
#include <string>

#define MAX 10
using namespace std;

int n, m;
string s;
int map[MAX][MAX];

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> s;

		for (int j = 0; j < m; j++) {
			map[i][j] = s[j] - '0';
		}
	}
}

void solution() {
	for (int i = 0; i < n; i++) {
		for (int j = m - 1; j >= 0; j--) {
			cout << map[i][j];
		}
		cout << "\n";
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