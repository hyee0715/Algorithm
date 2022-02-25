#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>

#define MAX 100
using namespace std;

int n;
char map[MAX][MAX];
bool visit[MAX][MAX];
pair<int, int> answer = make_pair(0, 0); // <적록색약이 아닌 사람이 봤을 때의 구역의 개수, 적록색약인 사람이 봤을 때의 구역의 개수>

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, - 1, 0, 0 };

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.size(); j++) {
			map[i][j] = s[j];
		}
	}
}

void bfs(int a, int b, char c) {
	queue<pair<int, int> > q;
	visit[a][b] = true;
	q.push(make_pair(a, b));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
				if (map[nx][ny] == c && visit[nx][ny] == false) {
					visit[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

void changeGintoA() {
	// G를 R로 변경
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'G') {
				map[i][j] = 'R';
			}
		}
	}
}

void solution() {
	// 적록색약이 아닌 사람
	memset(visit, false, sizeof(visit));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'R' && visit[i][j] == false) {
				answer.first++;
				bfs(i, j, map[i][j]);
			}

			if (map[i][j] == 'G' && visit[i][j] == false) {
				answer.first++;
				bfs(i, j, map[i][j]);
			}

			if (map[i][j] == 'B' && visit[i][j] == false) {
				answer.first++;
				bfs(i, j, map[i][j]);
			}
		}
	}

	// 적록색약인 사람
	memset(visit, false, sizeof(visit));

	changeGintoA();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'R' && visit[i][j] == false) {
				answer.second++;
				bfs(i, j, map[i][j]);
			}

			if (map[i][j] == 'B' && visit[i][j] == false) {
				answer.second++;
				bfs(i, j, map[i][j]);
			}
		}
	}

	// print answer
	cout << answer.first << " " << answer.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}