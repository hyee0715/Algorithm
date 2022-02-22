#include <iostream>
#include <cstring>
#include <string>
#include <queue>

#define MAX 100
using namespace std;

int n, m;
char map[MAX][MAX];
bool visit[MAX][MAX];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		
		for (int j = 0; j < s.size(); j++) {
			map[i][j] = s[j];
		}
	}
}

void bfs(int a, int b, int cnt) {
	queue<pair<pair<int, int>, int> > q;
	visit[a][b] = true;
	cnt++;
	q.push(make_pair(make_pair(a, b), cnt));

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int answer = q.front().second;
		q.pop();

		if (x == n - 1 && y == m - 1) {
			cout << answer;
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (map[nx][ny] == '1' && visit[nx][ny] == false) {
					visit[nx][ny] = true;
					q.push(make_pair(make_pair(nx, ny), answer + 1));
				}
			}
		}
	}
}

void solution() {
	bfs(0, 0, 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}