#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int bfs(vector<vector<int>>& map, vector<vector<bool>>& visit, int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a, b });
	visit[a][b] = true;

	int sum = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		sum += map[x][y];

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= map.size() || ny >= map[0].size()) {
				continue;
			}

			if (map[nx][ny] != -1 && visit[nx][ny] == false) {
				q.push({ nx, ny });
				visit[nx][ny] = true;
			}
		}
	}

	return sum;
}

vector<int> solution(vector<string> maps) {
	vector<int> answer;

	vector<vector<int>> map(maps.size(), vector<int>(maps[0].length()));
	vector<vector<bool>> visit(maps.size(), vector<bool>(maps[0].length(), false));

	for (int i = 0; i < maps.size(); i++) {
		for (int j = 0; j < maps[i].length(); j++) {
			if (maps[i][j] == 'X') {
				map[i][j] = -1;
				continue;
			}

			map[i][j] = maps[i][j] - '0';
		}
	}

	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			if (map[i][j] != -1 && visit[i][j] == false) {
				int n = bfs(map, visit, i, j);
				answer.push_back(n);
			}
		}
	}

	if (answer.empty()) {
		answer.push_back(-1);
		return answer;
	}

	sort(answer.begin(), answer.end());

	return answer;
}