class Solution {
public:
	vector<vector<int>> bfs(vector<vector<int>>& mat, vector<vector<bool>> visit, queue<pair<pair<int, int>, int>> q) {
		int dx[] = { 0, 0, 1, -1 };
		int dy[] = { 1, -1, 0, 0 };

		vector<vector<int>> answer(mat.size(), vector<int>(mat[0].size(), INT_MAX));

		while (!q.empty()) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int cnt = q.front().second;
			q.pop();

			answer[x][y] = min(answer[x][y], cnt);

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx >= mat.size() || ny >= mat[0].size()) {
					continue;
				}

				if (mat[nx][ny] != 0 && visit[nx][ny] == false) {
					q.push({ {nx, ny}, cnt + 1 });
					visit[nx][ny] = true;
				}
			}
		}

		return answer;
	}

	vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
		int dx[] = { 0, 0, 1, -1 };
		int dy[] = { 1, -1, 0, 0 };

		vector<vector<int>> answer;
		vector<vector<bool>> visit(mat.size(), vector<bool>(mat[0].size(), false));
		queue<pair<pair<int, int>, int>> q;

		for (int i = 0; i < mat.size(); i++) {
			for (int j = 0; j < mat[i].size(); j++) {
				if (mat[i][j] == 0) {
					for (int k = 0; k < 4; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];

						if (nx < 0 || ny < 0 || nx >= mat.size() || ny >= mat[0].size()) {
							continue;
						}

						if (mat[nx][ny] == 1 && visit[nx][ny] == false) {
							q.push({ {nx, ny}, 1 });
							visit[nx][ny] = true;
						}
					}
				}
			}
		}

		answer = bfs(mat, visit, q);

		for (int i = 0; i < answer.size(); i++) {
			for (int j = 0; j < answer[0].size(); j++) {
				if (answer[i][j] == INT_MAX) {
					answer[i][j] = 0;
				}
			}
		}

		return answer;
	}
};