class Solution {
public:
	void bfs(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& visit) {
		int dx[] = { 0, 0, 1, -1 };
		int dy[] = { 1, -1, 0, 0 };

		queue<pair<int, int>> q;
		q.push({ i, j });
		visit[i][j] = true;

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx < 0 || ny < 0 || nx >= board.size() || ny >= board[0].size()) {
					continue;
				}

				if (board[nx][ny] == 'X' && visit[nx][ny] == false) {
					visit[nx][ny] = true;
					q.push({ nx, ny });
				}
			}
		}
	}

	int countBattleships(vector<vector<char>>& board) {
		int answer = 0;

		vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));

		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				if (board[i][j] == 'X' && visit[i][j] == false) {
					answer++;
					bfs(board, i, j, visit);
				}
			}
		}

		return answer;
	}
};