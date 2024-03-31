#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<vector<int> > board, original;
vector<int> v;
queue<int> q;
int answer = 0;

void input() {
	cin >> n;

	original.assign(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> original[i][j];
		}
	}
}

void mergeBlocks(int& num, int block) {
	if (num == -1) {
		num = block;
	}
	else {
		if (num == block) {
			q.push(num + block);
			num = -1;
		}
		else {
			q.push(num);
			num = block;
		}
	}
}

void arrangeBlocks() {
	int num = -1;

	for (int dir : v) {
		if (dir == 0) { //블록이 합쳐지는 방향 : 동 (왼쪽으로 스왑)
			for (int i = 0; i < n; i++) {
				num = -1;

				for (int j = 0; j < n; j++) {
					if (board[i][j] == 0) continue;

					mergeBlocks(num, board[i][j]);
				}

				if (num != -1) {
					q.push(num);
				}

				//큐 비우기
				for (int j = 0; j < n; j++) {
					board[i][j] = 0;
				}

				int idx = 0;
				while (!q.empty()) {
					int qNum = q.front();
					q.pop();

					board[i][idx] = qNum;
					idx++;
				}
			}
		}
		else if (dir == 1) { //블록 합쳐지는 방향 : 북 (아래쪽으로 스왑)
			for (int j = 0; j < n; j++) {
				num = -1;

				for (int i = n - 1; i >= 0; i--) {
					if (board[i][j] == 0) continue;

					mergeBlocks(num, board[i][j]);
				}

				if (num != -1) {
					q.push(num);
				}

				//큐 비우기
				for (int i = 0; i < n; i++) {
					board[i][j] = 0;
				}

				int idx = n - 1;
				while (!q.empty()) {
					int qNum = q.front();
					q.pop();

					board[idx][j] = qNum;
					idx--;
				}
			}
		}
		else if (dir == 2) { //블록 합쳐지는 방향 : 서 (오른쪽으로 스왑)
			for (int i = 0; i < n; i++) {
				num = -1;

				for (int j = n - 1; j >= 0; j--) {
					if (board[i][j] == 0) continue;

					mergeBlocks(num, board[i][j]);
				}

				if (num != -1) {
					q.push(num);
				}

				//큐 비우기
				for (int j = 0; j < n; j++) {
					board[i][j] = 0;
				}

				int idx = n - 1;
				while (!q.empty()) {
					int qNum = q.front();
					q.pop();

					board[i][idx] = qNum;
					idx--;
				}
			}
		}
		else { //블록 합쳐지는 방향 : 남 (위로 스왑)
			for (int j = 0; j < n; j++) {
				num = -1;

				for (int i = 0; i < n; i++) {
					if (board[i][j] == 0) continue;

					mergeBlocks(num, board[i][j]);
				}

				if (num != -1) {
					q.push(num);
				}

				//큐 비우기
				for (int i = 0; i < n; i++) {
					board[i][j] = 0;
				}

				int idx = 0;
				while (!q.empty()) {
					int qNum = q.front();
					q.pop();

					board[idx][j] = qNum;
					idx++;
				}
			}
		}
	}
}

void copyBoard() {
	board.assign(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board[i][j] = original[i][j];
		}
	}
}

int findMaxBlock() {
	int num = -1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			num = max(num, board[i][j]);
		}
	}

	return num;
}

void dfs(int cnt) {
	if (cnt == 5) {
		copyBoard();

		arrangeBlocks();

		answer = max(answer, findMaxBlock());

		return;
	}

	for (int i = 0; i < 4; i++) {
		v.push_back(i);
		dfs(cnt + 1);
		v.pop_back();
	}
}

void solution() {
	dfs(0); //중복 순열

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