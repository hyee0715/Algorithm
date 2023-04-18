class Solution {
public:
	void bfs(vector<vector<char>>& board, vector<vector<bool>>& visit, int a, int b) {
		int dx[] = { 0, 0, -1, 1 };
		int dy[] = { -1, 1, 0, 0 };

		queue<pair<int, int>> q;
		queue<pair<int, int>> nonFlip;

		q.push({ a, b });
		nonFlip.push({ a, b });
		board[a][b] = 'X';
		visit[a][b] = true;

		bool onTheBoader = false;

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x == 0 || x == board.size() - 1 || y == 0 || y == board[0].size() - 1) {
				onTheBoader = true;
			}

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size()) {
					continue;
				}

				if (board[nx][ny] == 'O' && visit[nx][ny] == false) {
					q.push({ nx, ny });
					visit[nx][ny] = true;
					board[nx][ny] = 'X';

					nonFlip.push({ nx, ny });
				}
			}
		}

		if (onTheBoader) {
			while (!nonFlip.empty()) {
				int x = nonFlip.front().first;
				int y = nonFlip.front().second;
				nonFlip.pop();

				board[x][y] = 'O';
			}
		}
	}

	void solve(vector<vector<char>>& board) {
		vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));

		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] == 'O' && visit[i][j] == false) {
					bfs(board, visit, i, j);
				}
			}
		}
	}
};