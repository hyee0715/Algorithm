#include <iostream>
#include <queue>
#include <cstring>

#define MAX 100
using namespace std;

int n, m, outside_air_cnt, answer = 0;
int map[MAX][MAX];
bool visit[MAX][MAX], outside_air[MAX][MAX];
queue<pair<int, int> > melting_q;

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

void initialize() {
	memset(visit, false, sizeof(visit));
	memset(outside_air, false, sizeof(outside_air));
	outside_air[0][0] = true; // 초기 외부 공기를 (0,0)에 설정한다. 이후 find_outside_air()함수로 확신시킬 예정
}

bool all_melted() { // 치즈가 모두 녹았는지 확인
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1)
				return false;
		}
	}

	return true;
}

void find_outside_air(int a, int b) { // 외부 공기를 확산시켜 해당 위치에 outside_air[x][y] = true로 표시
	queue<pair<int, int> > q;
	q.push({ a, b });
	outside_air[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			if (map[nx][ny] == 0 && outside_air[nx][ny] == false) {
				outside_air[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}

void bfs(int a, int b) {
	queue<pair<int, int> > q;
	q.push({ a, b });
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		outside_air_cnt = 0;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			if (outside_air[nx][ny] == true) { // 주변에 외부 공기가 있다면 외부 공기 카운트 + 1
				outside_air_cnt++;
			}

			if (map[nx][ny] == 1 && visit[nx][ny] == false) {
				visit[nx][ny] = true;
				q.push({ nx, ny });
			}
		}

		if (outside_air_cnt >= 2) // 4변 중 2변 이상 외부 공기와 접촉되어 있다면 melting_q에 위치 삽입
			melting_q.push({ x, y });
	}
}

void solution() {
	initialize();

	while (1) {
		//맵 안의 치즈가 모두 녹은 상태인지 확인하고, 모두 녹았다면 정답 출력 후 리턴
		if (all_melted()) {
			cout << answer;
			return;
		}

		//외부 공기를 찾아 outside_air에 true 표시한다.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 0 && outside_air[i][j] == false) { // 맵에는 0(공기)으로, 외부공기는 false로 표시된 좌표 중에
					
					for (int k = 0; k < 4; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];

						if (nx >= 0 && ny >= 0 && nx < n && ny < m) { //상하좌우 중에 외부공기가 있다면 find_outside_air()함수 호출로 외부공기를 확산시킨다.
							if (outside_air[nx][ny] == true)
								find_outside_air(i, j);
						}
					}
				}
			}
		}

		//치즈 중 2변 이상이 외부 공기와 접촉되어있는지 파악하여 녹아야하는 치즈는 melting_q에 삽입한다.
		memset(visit, false, sizeof(visit));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 1 && visit[i][j] == false) {
					bfs(i, j);
				}
			}
		}

		//melting_q를 pop 하면서 치즈를 녹인다.
		while (!melting_q.empty()) {
			int x = melting_q.front().first;
			int y = melting_q.front().second;
			melting_q.pop();

			map[x][y] = 0;
		}
		
		answer++;
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