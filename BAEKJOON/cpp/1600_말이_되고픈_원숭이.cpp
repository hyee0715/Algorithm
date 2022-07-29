#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX 201
using namespace std;

int w, h, k, cnt = 0;
vector<vector<int> > map;
bool visit[MAX][MAX][31]; // visit[a][b][c]에서 c는 원숭이가 말 처럼 이동할 수 있는 횟수

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int h_dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int h_dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

void input() {
	cin >> k >> w >> h;

	for (int i = 0; i < h; i++) {
		vector<int> v;

		for (int j = 0; j < w; j++) {
			int a;
			cin >> a;
			v.push_back(a);
		}

		map.push_back(v);
	}
}

void bfs(int a, int b, int c) {
	queue<pair<pair<int, int>, pair<int, int> > > q; // x좌표, y좌표, 이동 동작 수, 말 처럼 이동한 횟수
	visit[a][b][0] = true;
	q.push({ {a, b}, {c, 0} });

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int count = q.front().second.first;
		int horse = q.front().second.second;
		q.pop();

		if (x == h - 1 && y == w - 1) {
			cout << count;
			return;
		}

		for (int i = 0; i < 4; i++) { // 인접한 네 방향으로 이동
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;

			if (map[nx][ny] == 0 && visit[nx][ny][horse] == false) {
				q.push({ {nx, ny}, {count + 1, horse} });
				visit[nx][ny][horse] = true;
			}
		}

		for (int i = 0; i < 8; i++) { // 말의 움직임으로 여덟 방향 이동
			int nx = x + h_dx[i];
			int ny = y + h_dy[i];

			if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;

			if (map[nx][ny] == 0 && visit[nx][ny][horse + 1] == false && horse < k) {
				q.push({ {nx, ny}, {count + 1, horse + 1} });
				visit[nx][ny][horse + 1] = true;
			}
		}
	}

	cout << -1;
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