#include <iostream>
using namespace std;

int n, m, cnt = 1;

void input() {
	cin >> n >> m;
}

void solution() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j == m - 1)
				cout << cnt;
			else
				cout << cnt << " ";

			cnt++;
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