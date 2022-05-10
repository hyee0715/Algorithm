#include <iostream>

#define MAX 2200
using namespace std;

int n;
int map[MAX][MAX];
int minus_one_cnt = 0, zero_cnt = 0, one_cnt = 0;

void input() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
}

bool all_same(int x, int y, int size) {
	int num = map[x][y];

	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (map[i][j] != num)
				return false;
		}
	}

	return true;
}

void check(int x, int y, int size) {
	if (all_same(x, y, size)) {
		if (map[x][y] == -1)
			minus_one_cnt++;
		else if (map[x][y] == 0)
			zero_cnt++;
		else //map[x][y] == 1
			one_cnt++;
	}
	else {
		check(x, y, size / 3);
		check(x, y + size / 3, size / 3);
		check(x, y + 2 * (size / 3), size / 3);

		check(x + size / 3, y, size / 3);
		check(x + size / 3, y + size / 3, size / 3);
		check(x + size / 3, y + 2 * (size / 3), size / 3);

		check(x + 2 * (size / 3), y, size / 3);
		check(x + 2 * (size / 3), y + size / 3, size / 3);
		check(x + 2 * (size / 3), y + 2 * (size / 3), size / 3);
	}
}

void solution() {
	check(1, 1, n);

	cout << minus_one_cnt << "\n" << zero_cnt << "\n" << one_cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}