#include <vector>
#include <queue>
using namespace std;

int bfs(vector<vector<int>>& maps, vector<vector<bool>>& visit, int a, int b) {
	int dx[] = { 0, 0, 1, -1 };
	int dy[] = { 1, -1, 0, 0 };

	queue<pair<pair<int, int>, int>> q; //x, y, cnt
	q.push({ {a, b}, 1 });
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (x == maps.size() - 1 && y == maps[0].size() - 1) {
			return cnt;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= maps.size() || ny >= maps[0].size()) {
				continue;
			}

			if (maps[nx][ny] == 1 && visit[nx][ny] == false) {
				q.push({ {nx, ny}, cnt + 1 });
				visit[nx][ny] = true;
			}
		}
	}

	return -1;
}
int solution(vector<vector<int>> maps)
{
	int answer = 0;
	vector<vector<bool>> visit(maps.size(), vector<bool>(maps[0].size()));

	answer = bfs(maps, visit, 0, 0);
	return answer;
}