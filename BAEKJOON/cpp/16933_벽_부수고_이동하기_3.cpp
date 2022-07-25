#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>

#define MAX 1000
using namespace std;

int n, m, k, cnt = 1;
vector<vector<int> > map;
bool visit[MAX][MAX][11][2]; //visit[a][b][c][d] : c == 벽을 부수는 횟수, d == 낮(0), 밤(0)

int dx[] = { 0, 0, 0, 1, -1 };
int dy[] = { 0, 1, -1, 0, 0 };

void input() {
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		vector<int> v;
		for (int j = 0; j < m; j++) {
			v.push_back(s[j] - '0');
		}

		map.push_back(v);
	}
}

void bfs(int a, int b, int c) { // c : 이동 횟수
	queue<pair<pair<pair<int, int>, pair<int, int> >, int> > q; //x좌표, y좌표, 벽을 부순 횟수, 낮(0)/밤(1)여부, 이동 횟수 
	q.push({ {{a, b}, {0, 0}}, cnt });
	visit[a][b][0][0] = true;

	while (!q.empty()) {
		int x = q.front().first.first.first;
		int y = q.front().first.first.second;
		int wall_cnt = q.front().first.second.first;
		int time = q.front().first.second.second;
		int cnt = q.front().second;
		q.pop();

		if (x == n - 1 && y == m - 1) {
			cout << cnt;
			return;
		}

		for (int i = 0; i < 5; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			//이동하지 않고 같은 칸에 머물러 있는 경우 (낮인 경우 -> 밤으로 변경)
			if (x == nx && y == ny && time == 0 && visit[nx][ny][wall_cnt][time + 1] == false) {
				q.push({ {{nx, ny}, {wall_cnt, time + 1}}, cnt + 1 });
				visit[nx][ny][wall_cnt][time + 1] = true;
			}

			//이동하지 않고 같은 칸에 머물러 있는 경우 (밤인 경우 -> 낮으로 변경)
			else if (x == nx && y == ny && time == 1 && visit[nx][ny][wall_cnt][time - 1] == false) {
				q.push({ {{nx, ny}, {wall_cnt, time - 1}}, cnt + 1 });
				visit[nx][ny][wall_cnt][time - 1] = true;
			}

			//벽이 없는 경우 (낮인 경우 -> 밤으로 변경)
			else if (map[nx][ny] == 0 && visit[nx][ny][wall_cnt][time + 1] == false && time == 0) {
				q.push({ {{nx, ny}, {wall_cnt, time + 1}}, cnt + 1 });
				visit[nx][ny][wall_cnt][time + 1] = true;
			}

			//벽이 없는 경우 (밤인 경우 -> 낮으로 변경)
			else if (map[nx][ny] == 0 && visit[nx][ny][wall_cnt][time - 1] == false && time == 1) {
				q.push({ {{nx, ny}, {wall_cnt, time - 1}}, cnt + 1 });
				visit[nx][ny][wall_cnt][time - 1] = true;
			}

			//벽이 있을 때 벽을 부수는 경우 (낮에만 가능)
			else if (map[nx][ny] == 1 && visit[nx][ny][wall_cnt + 1][time + 1] == false && wall_cnt < k && time == 0) {
				q.push({ {{nx, ny}, {wall_cnt + 1, time + 1}}, cnt + 1 });
				visit[nx][ny][wall_cnt + 1][time + 1] = true;
			}
		}
	}

	cout << "-1";
}

void solution() {
	memset(visit, false, sizeof(visit));

	bfs(0, 0, cnt);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}