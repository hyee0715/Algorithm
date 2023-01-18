class Solution {
public:
	void bfs(vector<vector<int>>& rooms, queue<pair<int, int>> q, vector<vector<bool>>& visit) {
		int dx[4] = { 0, 0, 1, -1 };
		int dy[4] = { 1, -1, 0, 0 };

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx >= rooms.size() || ny >= rooms[0].size()) continue;

				if (rooms[nx][ny] != -1 && visit[nx][ny] == false) {
					q.push({ nx, ny });
					visit[nx][ny] = true;
					rooms[nx][ny] = min(rooms[nx][ny], rooms[x][y] + 1);
				}
			}
		}
	}

	void wallsAndGates(vector<vector<int>>& rooms) {
		queue<pair<int, int>> q;
		vector<vector<bool>> visit(rooms.size(), vector<bool>(rooms[0].size(), false));

		for (int i = 0; i < rooms.size(); i++) {
			for (int j = 0; j < rooms[i].size(); j++) {
				if (rooms[i][j] == 0) {
					q.push({ i, j });
					visit[i][j] = true;
				}
			}
		}

		bfs(rooms, q, visit);
	}
};