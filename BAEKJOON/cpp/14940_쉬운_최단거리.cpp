#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define MAX 1000
using namespace std;

int n, m, cnt = 1;
int map[MAX][MAX];
int answer[MAX][MAX];
bool visit[MAX][MAX];
pair<int, int> start;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void input() {
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

			if (map[i][j] == 2) {
				start = make_pair(i, j);
				
			}
		}
	}
}

void bfs() {
	queue<pair<int, int> > q;
	q.push(make_pair(start.first, start.second));
	visit[start.first][start.second] = true;

	while (!q.empty()) {
		int qs = q.size();

		for (int k = 0; k < qs; k++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
					if (map[nx][ny] == 1 && visit[nx][ny] == false) {
						answer[nx][ny] = cnt;
						q.push(make_pair(nx, ny));
						visit[nx][ny] = true;;
					}
				}
			}
		}
		
		cnt++;
	}
}

void copyMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			answer[i][j] = map[i][j];
		}
	}
}

void solution() {
	memset(visit, false, sizeof(visit));

	copyMap();

	bfs();

	//answer배열의 시작 위치(2)를 0으로 변경
	answer[start.first][start.second] = 0;

	// 원래 갈 수 있는 땅이지만 도달할 수 없는 위치 -1로 표시
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (answer[i][j] == 1 && visit[i][j] == false)
				answer[i][j] = -1;
		}
	}

	//print answer
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}