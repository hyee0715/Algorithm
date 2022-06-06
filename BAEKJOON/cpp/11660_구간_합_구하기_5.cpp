#include <iostream>

#define MAX 1025
using namespace std;

int n, m, answer;
int map[MAX][MAX], sum[MAX][MAX];

void input() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
}

void make_sum() {
	sum[1][1] = map[1][1];

	for (int i = 2; i <= n; i++) {
		sum[1][i] = sum[1][i - 1] + map[1][i];
		sum[i][1] = sum[i - 1][1] + map[i][1];
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + map[i][j];
		}
	}
}

void solution() {
	make_sum();

	int x1, y1, x2, y2;

	for (int i = 0; i < m; i++) {
		answer = 0;

		cin >> x1 >> y1 >> x2 >> y2;

		if (x1 == 1) 
			answer = sum[x2][y2] - sum[x2][y1 - 1];
		else if (y1 == 1) 
			answer = sum[x2][y2] - sum[x1 - 1][y2];
		else 
			answer = sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];

		cout << answer << "\n";
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