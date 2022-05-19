#include <iostream>
#include <string>

#define MAX 65
using namespace std;

int n;
string answer = "";
char map[MAX][MAX];

void input() {
	cin >> n;

	string s;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 1; j <= n; j++) {
			map[i][j] = s[j - 1];
		}
	}
}

bool is_filled(int x, int y, int size) {
	char color = map[x][y];

	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (map[i][j] != color)
				return false;
		}
	}

	return true;
}

void check(int x, int y, int size) {
	if (is_filled(x, y, size)) {
		if (map[x][y] == '0')
			answer += '0';
		else
			answer += '1';

		return;
	}
	else {
		answer += "(";

		check(x, y, size / 2);
		check(x, y + (size / 2), size / 2);
		check(x + (size / 2), y, size / 2);
		check(x + (size / 2), y + (size / 2), size / 2);
	}

	answer += ")";
}

void solution() {
	check(1, 1, n);

	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}