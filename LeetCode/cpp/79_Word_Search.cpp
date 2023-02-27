class Solution {
public:
	bool dfs(vector<vector<char>>& board, string word, vector<vector<bool>>& visit, int x, int y, int idx) {
		if (idx == word.length()) {
			return true;
		}

		int dx[] = { 0, 0, 1, -1 };
		int dy[] = { 1, -1, 0, 0 };

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size()) {
				continue;
			}

			if (board[nx][ny] == word[idx] && visit[nx][ny] == false) {
				visit[nx][ny] = true;
				if (dfs(board, word, visit, nx, ny, idx + 1)) {
					return true;
				}
				visit[nx][ny] = false;
			}
		}

		return false;
	}

	bool exist(vector<vector<char>>& board, string word) {
		vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));

		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] == word[0]) {
					visit.assign(board.size(), vector<bool>(board[0].size(), false));

					visit[i][j] = true;
					if (dfs(board, word, visit, i, j, 1)) {
						return true;
					}
				}
			}
		}

		return false;
	}
};