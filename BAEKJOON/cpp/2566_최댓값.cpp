#include <iostream>
#include <vector>
using namespace std;

int map[10][10];
pair<int, pair<int, int>> answer = { -1, {-1, -1} };

void input() {
	int n;

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> n;
			map[i][j] = n;
		}
	}
}

void solution() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (map[i][j] > answer.first) {
				answer.first = map[i][j];
				answer.second.first = i;
				answer.second.second = j;
			}
		}
	}

	cout << answer.first << "\n" << answer.second.first << " " << answer.second.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}