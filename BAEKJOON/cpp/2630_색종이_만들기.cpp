#include <iostream>

#define MAX 129
using namespace std;

int n, white = 0, blue = 0;
int map[MAX][MAX];

void input() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
}

bool is_filled(int x, int y, int size) {
	int paper = map[x][y];

	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (map[i][j] != paper)
				return false;
		}
	}

	return true;
}

void check(int x, int y, int size) {
	if (is_filled(x, y, size)) {
		if (map[x][y] == 0) //하얀색
			white++;
		else
			blue++;
		
		return;
	}
	else {
		check(x, y, size / 2);
		check(x, y + (size / 2), size / 2);
		check(x + (size / 2), y, size / 2);
		check(x + (size / 2), y + (size / 2), size / 2);
	}
}

void solution() {
	check(1, 1, n);

	cout << white << "\n" << blue;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}