#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int bfs(int a, int b, vector<vector<bool>>& visit, vector<vector<int>>& picture) {
	int cnt = 0;

	int dx[] = { 0, 0, 1, -1 };
	int dy[] = { 1, -1, 0, 0 };

	queue<pair<int, int>> q;
	q.push({ a, b });
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		cnt++;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= picture.size() || ny >= picture[0].size()) {
				continue;
			}

			if (picture[nx][ny] == picture[x][y] && visit[nx][ny] == false) {
				visit[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}

	return cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	vector<int> answer;
	vector<vector<bool>> visit(m, vector<bool>(n, false));

	int count = 0, maxSpace = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (picture[i][j] != 0 && visit[i][j] == false) {
				maxSpace = max(maxSpace, bfs(i, j, visit, picture));
				count++;
			}
		}
	}

	answer = { count, maxSpace };

	return answer;
}