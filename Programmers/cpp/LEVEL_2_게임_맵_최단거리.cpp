#include <vector>
#include <queue>
using namespace std;

int bfs(vector<vector<int>>& map) {
	int dx[] = { 0, 0, 1, -1 };
	int dy[] = { 1, -1, 0, 0 };

	int count = -1;

	vector<vector<bool>> visit(map.size(), vector<bool>(map[0].size(), false));
	queue<pair<pair<int, int>, int>> q;
	q.push({ {0, 0}, 1 });
	visit[0][0] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (x == map.size() - 1 && y == map[0].size() - 1) {
			count = cnt;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= map.size() || ny >= map[0].size()) continue;

			if (map[nx][ny] == 1 && visit[nx][ny] == false) {
				q.push({ {nx, ny}, cnt + 1 });
				visit[nx][ny] = true;
			}
		}
	}

	return count;
}

int solution(vector<vector<int> > maps)
{
	int answer = bfs(maps);

	return answer;
}