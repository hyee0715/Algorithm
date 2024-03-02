#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int r, c, t;
vector<vector<int>> map;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void input() {
	cin >> r >> c >> t;

	map.assign(r, vector<int>(c, 0));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}
}

vector<vector<int>> findCleanerLocation() {
	vector<int> a, b;

	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			if (map[i][j] == -1) {
				if (a.empty()) {
					a = { i, j };
				}
				else {
					b = { i, j };
				}
			}
		}
	}

	return { a, b };
}

void addDustToQueueToSpread(int x, int y, queue<pair<pair<int, int>, int>>& q) {
	int dust = map[x][y];
	int diffusedDust = dust / 5;

	int areaCount = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= map.size() || ny >= map[0].size() || map[nx][ny] == -1) {
			continue;
		}

		areaCount++;
		q.push({ {nx, ny}, diffusedDust });
	}

	int remainingDust = dust - (diffusedDust * areaCount);
	map[x][y] = remainingDust;
}

void spreadDust(queue<pair<pair<int, int>, int>>& q) {
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dust = q.front().second;
		q.pop();

		map[x][y] += dust;
	}
}

void startCleanerCounterclockwiseDirection(vector<int>& cleanerLocation) {
	int x = cleanerLocation[0];
	int y = cleanerLocation[1];

	vector<int> v;

	for (int i = y; i < map[0].size(); i++) {
		v.push_back(map[x][i]);
		
		if (i == y) {
			v.push_back(0);
		}
	}

	for (int i = x - 1; i >= 0; i--) {
		v.push_back(map[i][map[0].size() - 1]);
	}

	for (int i = map[0].size() - 2; i > 0; i--) {
		v.push_back(map[0][i]);
	}

	for (int i = 0; i < x; i++) {
		v.push_back(map[i][0]);
	}

	for (int i = 0; i < y; i++) {
		v.push_back(map[x][i]);
	}

	v.pop_back();

	int idx = 0;
	for (int i = y; i < map[0].size() - 1; i++) {
		map[x][i] = v[idx++];
	}

	for (int i = x; i > 0; i--) {
		map[i][map[0].size() - 1] = v[idx++];
	}

	for (int i = map[0].size() - 1; i > 0; i--) {
		map[0][i] = v[idx++];
;	}

	for (int i = 0; i < x; i++) {
		map[i][0] = v[idx++];
	}

	for (int i = 0; i < y; i++) {
		map[x][i] = v[idx++];
	}
}

void startCleanerClockwiseDirection(vector<int>& cleanerLocation) {
	int x = cleanerLocation[0];
	int y = cleanerLocation[1];

	vector<int> v;

	for (int i = y; i < map[0].size(); i++) {
		v.push_back(map[x][i]);

		if (i == y) {
			v.push_back(0);
		}
	}

	for (int i = x + 1; i < map.size(); i++) {
		v.push_back(map[i][map[0].size() - 1]);
	}

	for (int i = map[0].size() - 2; i > 0; i--) {
		v.push_back(map[map.size() - 1][i]);
	}

	for (int i = map.size() - 1; i > x; i--) {
		v.push_back(map[i][0]);
	}

	for (int i = 0; i < y; i++) {
		v.push_back(map[x][i]);
	}

	v.pop_back();

	int idx = 0;
	for (int i = y; i < map[0].size() - 1; i++) {
		map[x][i] = v[idx++];
	}

	for (int i = x; i < map.size() - 1; i++) {
		map[i][map[0].size() - 1] = v[idx++];
	}

	for (int i = map[0].size() - 1; i > 0; i--) {
		map[map.size() - 1][i] = v[idx++];
	}

	for (int i = map.size() - 1; i > x; i--) {
		map[i][0] = v[idx++];
	}

	for (int i = 0; i < y; i++) {
		map[x][i] = v[idx++];
	}
}

int getAnswer() {
	int sum = 0;

	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[0].size(); j++) {
			if (map[i][j] == -1) {
				continue;
			}

			sum += map[i][j];
		}
	}

	return sum;
}

void solution() {
	vector<vector<int>> cleanerLocation = findCleanerLocation();
	queue<pair<pair<int, int>, int>> q; //확산 시킬 x, y좌표, 먼지 양

	for (int cnt = 0; cnt < t; cnt++) {
		for (int i = 0; i < map.size(); i++) {
			for (int j = 0; j < map[i].size(); j++) {
				if (map[i][j] != -1) { //해당 칸이 청소기 위치가 아니라면
					addDustToQueueToSpread(i, j, q);
				}
			}
		}

		spreadDust(q);

		startCleanerCounterclockwiseDirection(cleanerLocation[0]); //반시계 방향
		startCleanerClockwiseDirection(cleanerLocation[1]); //시계 방향
	}

	int answer = getAnswer();
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