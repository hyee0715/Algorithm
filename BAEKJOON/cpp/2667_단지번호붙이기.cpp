#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

#define MAX 25
using namespace std;

int n, cnt = 0;
char map[MAX][MAX];
bool visit[MAX][MAX];
vector<int> answer;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

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

			if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
				if (map[nx][ny] == '1' && visit[nx][ny] == false) {
					q.push(make_pair(nx, ny));
					visit[nx][ny] = true;
					cnt++;
				}
			}
		}
	}

	answer.push_back(cnt);
}

void solution() {
	memset(visit, false, sizeof(visit));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == '1' && visit[i][j] == false) {
				bfs(i, j);
				cnt = 0;
			}
		}
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << "\n";
	
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
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