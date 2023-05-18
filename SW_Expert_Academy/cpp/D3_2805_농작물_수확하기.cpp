#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
vector<vector<int>> board;

void initialize() {
	board.clear();
}

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		vector<int> v;
		for (int j = 0; j < n; j++) {
			v.push_back(s[j] - '0');
		}

		board.push_back(v);
	}
}

void solution() {
	int answer = 0;
	int cnt = 0;

	bool up = true;

	for (int i = 0; i < board.size(); i++) {
		answer += board[i][n / 2];

		for (int j = 1; j <= cnt; j++) {
			answer += board[i][(n / 2) + j];
			answer += board[i][(n / 2) - j];
		}

		if (cnt == n / 2) {
			up = false;
		}

		if (up) {
			cnt++;
		}
		else {
			cnt--;
		}
	}

	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 1; i <= tc; i++) {
		initialize();
		input();

		cout << "#" << i << " ";
		solution();
		cout << "\n";
	}

	return 0;
}