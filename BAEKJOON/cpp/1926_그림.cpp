#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 500
using namespace std;

int n, m, cnt;
int map[MAX][MAX];
bool visit[MAX][MAX];
vector<int> answer;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
}

void bfs(int a, int b) {
	queue<pair<int, int> > q;
	q.push(make_pair(a, b));
	visit[a][b] = true;
	cnt++;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				if (map[nx][ny] == 1 && visit[nx][ny] == false) {
					visit[nx][ny] = true;
					cnt++;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	
	answer.push_back(cnt);
}

void solution() {
	memset(visit, false, sizeof(visit));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && visit[i][j] == false) {
				cnt = 0;
				bfs(i, j);
			}
		}
	}

	if (answer.size() == 0) {
		cout << 0 << "\n" << 0;
		return;
	}
	
	cout << answer.size() << "\n";
	sort(answer.begin(), answer.end(), greater<>());
	cout << answer[0];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}