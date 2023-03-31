#include <string>
#include <vector>
#include <queue>

using namespace std;

// 한 칸 이동하는 데 1초, 도착 지점까지 걸리는 시간 구하기
int bfs(vector<vector<char>>& map, vector<vector<bool>>& visit, pair<int, int> start, pair<int, int> end) {
	int dx[] = { 0, 0, 1, -1 };
	int dy[] = { 1, -1, 0, 0 };

	queue<pair<pair<int, int>, int>> q; //x, y, 걸린 시간
	q.push({ {start.first, start.second}, 0 });
	visit[start.first][start.second] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (x == end.first && y == end.second) {
			return cnt;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= map.size() || ny >= map[0].size()) {
				continue;
			}

			if (map[nx][ny] != 'X' && visit[nx][ny] == false) {
				visit[nx][ny] = true;
				q.push({ {nx, ny}, cnt + 1 });
			}
		}
	}

	return -1;
}

int solution(vector<string> maps) {
	int answer = 0;
	vector<vector<char>> map(maps.size(), vector<char>(maps[0].length()));
	vector<vector<bool>> visit(maps.size(), vector<bool>(maps[0].length(), false));

	pair<int, int> start, end, lv;

	for (int i = 0; i < maps.size(); i++) {
		for (int j = 0; j < maps[i].length(); j++) {
			map[i][j] = maps[i][j];

			if (maps[i][j] == 'S') {
				start = { i, j };
			}
			else if (maps[i][j] == 'E') {
				end = { i, j };
			}
			else if (maps[i][j] == 'L') {
				lv = { i, j };
			}
		}
	}

	//출발점 -> 레버
	answer = bfs(map, visit, start, lv);

	if (answer == -1) {
		return answer;
	}

	visit.assign(maps.size(), vector<bool>(maps[0].length(), false));
	//레버 -> 도착점
	int n = bfs(map, visit, lv, end);

	if (n == -1) {
		return -1;
	}

	answer += n;
	return answer;
}