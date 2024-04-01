#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, l;
vector<vector<int>> board;
int answer = 0;

void input() {
	cin >> n >> l;

	board.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
}

bool checkRow(int i, int j) {
	for (int k = 1; k < l; k++) {
		if (j + k >= n) {
			return false;
		}

		if (board[i][j] != board[i][j + k]) {
			return false;
		}
	}

	return true;
}

bool checkCol(int i, int j) {
	for (int k = 1; k < l; k++) {
		if (i + k >= n) {
			return false;
		}

		if (board[i][j] != board[i + k][j]) {
			return false;
		}
	}

	return true;
}

void solution() {
	// 동 -> 서
	for (int i = 0; i < n; i++) {
		int cur = -1, seq = -1;
		bool incline = false;
		bool fail = false;

		for (int j = 0; j < n; j++) {
			if (cur == -1 && seq == -1) {
				cur = board[i][j];
				seq = 1;
				incline = false;

				continue;
			}

			if (cur == board[i][j]) {
				seq++;

				if (seq > l) {
					if (incline) {
						incline = false;
						seq = 1;
					}
				}
			}
			else {
				if (abs(cur - board[i][j]) > 1) {
					fail = true;
					break;
				}

				if (cur > board[i][j]) {
					if (checkRow(i, j)) {
						cur = board[i][j];
						seq = 1;
						incline = true;
					}
					else {
						fail = true;
						break;
					}
				}
				else {
					if (seq < l) {
						fail = true;
						break;
					}

					if (incline) {
						fail = true;
						break;
					}
					else {
						cur = board[i][j];
						seq = 1;
						incline = false;
					}
				}
			}
		}

		if (!fail) {
			answer++;
		}
	}

	//북 -> 남
	for (int j = 0; j < n; j++) {
		int cur = -1, seq = -1;
		bool incline = false;
		bool fail = false;

		for (int i = 0; i < n; i++) {
			if (cur == -1 && seq == -1) {
				cur = board[i][j];
				seq = 1;
				incline = false;

				continue;
			}

			if (cur == board[i][j]) {
				seq++;

				if (seq > l) {
					if (incline) {
						incline = false;
						seq = 1;
					}
				}
			}
			else {
				if (abs(cur - board[i][j]) > 1) {
					fail = true;
					break;
				}

				if (cur > board[i][j]) {
					if (checkCol(i, j)) {
						cur = board[i][j];
						seq = 1;
						incline = true;
					}
					else {
						fail = true;
						break;
					}
				}
				else {
					if (seq < l) {
						fail = true;
						break;
					}

					if (incline) {
						fail = true;
						break;
					}
					else {
						cur = board[i][j];
						seq = 1;
						incline = false;
					}
				}
			}
		}

		if (!fail) {
			answer++;
		}
	}

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