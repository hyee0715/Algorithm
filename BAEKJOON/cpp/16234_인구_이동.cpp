#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>
using namespace std;

int n, l, r;
vector<vector<int> > contries;

int dx[] = {0, 0, 1, -1}; 
int dy[] = {1, -1, 0, 0};

void input() {
	cin >> n >> l >> r;

	contries.assign(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> contries[i][j];
		}
	}
}

void bfs(int a, int b, vector<vector<bool>>& visit, unordered_map<int, vector<pair<pair<int, int>, int>>>& teams, int teamNum) {
	queue<pair<int, int>> q;

	q.push({ a, b });
	visit[a][b] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		teams[teamNum].push_back({ {x, y}, contries[x][y] });

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) {
				continue;
			}

			int diff = abs(contries[x][y] - contries[nx][ny]);

			if (diff >= l && diff <= r && visit[nx][ny] == false) {
				visit[nx][ny] = true;
				q.push({ nx, ny });
			}
		}
	}
}

void solution() {
	int days = 0;

	while (1) {
		//연합 찾기
		bool noTeam = true;

		int teamNum = 1;
		vector<vector<bool>> visit(n, vector<bool>(n, false));
		unordered_map<int, vector<pair<pair<int, int>, int>>> teams; // key : 연합 번호 / value : x, y, 인구 수

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visit[i][j] == false) {
					for (int k = 0; k < 4; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];

						if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
					
						int diff = abs(contries[i][j] - contries[nx][ny]);

						if (diff >= l && diff <= r) {
							bfs(i, j, visit, teams, teamNum);

							teamNum++;

							noTeam = false;

							break;
						}
					}
				}
			}
		}

		if (noTeam) {
			break;
		}

		//인구 이동
		for (auto team : teams) {
			vector<pair<pair<int, int>, int>> unit = team.second;

			int populationSum = 0;

			for (pair<pair<int, int>, int> contry : unit) {
				int population = contry.second;

				populationSum += population;
			}

			int contriesSize = unit.size();
			int dividedPopulation = populationSum / contriesSize;

			for (pair<pair<int, int>, int> contry : unit) {
				int x = contry.first.first;
				int y = contry.first.second;

				contries[x][y] = dividedPopulation;
			}
		}

		days++;
	}

	cout << days;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}