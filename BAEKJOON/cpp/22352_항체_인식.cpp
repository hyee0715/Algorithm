#include <iostream>
#include <cstring>
#include <queue>

#define MAX 30
using namespace std;

int n, m;
int before_map[MAX][MAX];
int after_map[MAX][MAX];
bool visit[MAX][MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> before_map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> after_map[i][j];
		}
	}
}

void bfs(int a, int b, int before, int after) {
	queue<pair<int, int> > q;
	q.push({ a, b });
	visit[a][b] = true;
	before_map[a][b] = after;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (before_map[nx][ny] == before && visit[nx][ny] == false) {
				before_map[nx][ny] = after;
				visit[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

bool compare_maps() { // before_map과 after_map을 비교
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (before_map[i][j] != after_map[i][j]) {
				return false;
			}
		}
	}

	return true;
}

void doing_bfs() { // bfs를 한 번만 실행하기 위해 함수로 만듦
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (before_map[i][j] != after_map[i][j]) {
				bfs(i, j, before_map[i][j], after_map[i][j]);
				return;
			}
		}
	}
}

void solution() {
	memset(visit, false, sizeof(visit));

	doing_bfs();

	// bfs 후의 before_map이 after_map과 같은지 확인
	// 같다면 YES 출력, 같지 않다면 NO 출력
	if (compare_maps())
		cout << "YES";
	else
		cout << "NO";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}