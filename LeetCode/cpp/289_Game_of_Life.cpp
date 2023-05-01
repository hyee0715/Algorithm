class Solution {
public:
	int check(vector<vector<int>>& board, int x, int y) {
		int dx[] = { 0, 0, 1, -1, -1, -1, 1, 1 };
		int dy[] = { 1, -1, 0, 0, -1, 1, -1, 1 };

		int cnt = 0;

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size()) {
				continue;
			}

			if (board[nx][ny] == 1) {
				cnt++;
			}
		}

		return cnt;
	}

	void gameOfLife(vector<vector<int>>& board) {
		queue<int> q;

		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				int neighbors = check(board, i, j);

				if (board[i][j] == 1) {
					if (neighbors == 2 || neighbors == 3) {
						q.push(1);
					}
					else {
						q.push(0);
					}
				}
				else {
					if (neighbors == 3) {
						q.push(1);
					}
					else {
						q.push(0);
					}
				}
			}
		}

		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				board[i][j] = q.front();
				q.pop();
			}
		}
	}
};