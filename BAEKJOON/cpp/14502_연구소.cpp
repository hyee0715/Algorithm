#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

#define MAX 8
using namespace std;

int n, m, answer = -1;
vector<vector<int>> map, c_map;
bool visit[MAX][MAX];
vector<pair<int, int>> empty_slot; // 초기 상태의 빈 칸 위치 저장
vector<int> comb_visit(64, false);
vector<int> comb_v;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		vector<int> v;
		int a;

		for (int j = 0; j < m; j++) {
			cin >> a;
			v.push_back(a);
		}

		map.push_back(v);
	}
}

void find_empty() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				empty_slot.push_back({ i, j });
			}
		}
	}
}

//구한 조합으로 벽 세우기
void make_wall(vector<int> comb_v) {
	c_map.clear();

	// map 복사
	for (int i = 0; i < n; i++) {
		vector<int> v;
		for (int j = 0; j < m; j++) {
			v.push_back(map[i][j]);
		}
		c_map.push_back(v);
	}

	//벽 세우기
	for (int i = 0; i < comb_v.size(); i++) {
		int x = empty_slot[comb_v[i]].first;
		int y = empty_slot[comb_v[i]].second;

		c_map[x][y] = 1;
	}
}

void bfs(int a, int b) {
	queue<pair<int, int>> q;
	visit[a][b] = true;
	q.push({ a, b });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			if (c_map[nx][ny] == 0 && visit[nx][ny] == false) {
				c_map[nx][ny] = 2;
				visit[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}

// 안전 영역 크기 구하기
int find_safe_zone_size() {
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c_map[i][j] == 0) {
				cnt++;
			}
		}
	}

	return cnt;
}

// 조합으로 벽 세울 곳 구하기
void dfs(int idx, int cnt) {
	if (cnt == 3) {
		// 구한 조합으로 map에 벽 세우기
		make_wall(comb_v);

		// 바이러스 퍼뜨리기
		memset(visit, false, sizeof(visit));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (c_map[i][j] == 2 && visit[i][j] == false) {
					bfs(i, j);
				}
			}
		}

		answer = max(answer, find_safe_zone_size());
	}
	else {
		for (int i = idx; i < empty_slot.size(); i++) {
			if (comb_visit[i] == true) continue;
			comb_visit[i] = true;
			comb_v.push_back(i);
			dfs(i, cnt + 1);
			comb_v.pop_back();
			comb_visit[i] = false;
		}
	}
}

void solution() {
	find_empty();

	dfs(0, 0);

	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}