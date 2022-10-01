#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<char>> map;
vector<pair<int, int>> empty_arr, obstacle, teachers;
vector<bool> visit;

void input() {
	cin >> n;

	map.assign(n, vector<char>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];

			if (map[i][j] == 'X')
				empty_arr.push_back({ i, j });

			if (map[i][j] == 'T')
				teachers.push_back({ i, j });
		}
	}
}

vector<vector<char>> map_copy() {
	vector<vector<char>> mp(map.size(), vector<char>(map[0].size()));

	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			mp[i][j] = map[i][j];
		}
	}

	return mp;
}

bool teachers_watching(vector<pair<int, int>> obstacle) {
	vector<vector<char>> cp_map = map_copy();

	// 장애물 설치
	for (int i = 0; i < obstacle.size(); i++) {
		int x = obstacle[i].first;
		int y = obstacle[i].second;

		cp_map[x][y] = 'O';
	}

	// 선생님 상하좌우 감시
	for (int i = 0; i < teachers.size(); i++) {

		// 위
		for (int j = teachers[i].first; j >= 0; j--) {
			//학생 발견 시 false 리턴
			if (cp_map[j][teachers[i].second] == 'S')
				return false;
			//장애물 발견 시 다음 방향
			else if (cp_map[j][teachers[i].second] == 'O')
				break;
		}

		//아래
		for (int j = teachers[i].first; j < cp_map.size(); j++) {
			//학생 발견 시 false 리턴
			if (cp_map[j][teachers[i].second] == 'S')
				return false;
			//장애물 발견 시 다음 방향
			else if (cp_map[j][teachers[i].second] == 'O')
				break;
		}

		//왼쪽
		for (int j = teachers[i].second; j >= 0; j--) {
			if (cp_map[teachers[i].first][j] == 'S')
				return false;
			//장애물 발견 시 다음 방향
			else if (cp_map[teachers[i].first][j] == 'O')
				break;
		}

		//오른쪽
		for (int j = teachers[i].second; j < cp_map[0].size(); j++) {			if (cp_map[teachers[i].first][j] == 'S')
				return false;
			//장애물 발견 시 다음 방향
			else if (cp_map[teachers[i].first][j] == 'O')
				break;
		}
	}

	return true;
}

void dfs(int idx, int cnt) {
	if (cnt == 3) {
		if (teachers_watching(obstacle)) {
			cout << "YES";
			exit(0);
		}
	}
	else {
		for (int i = idx; i < empty_arr.size(); i++) {
			if (visit[i] == true) continue;
			visit[i] = true;
			obstacle.push_back(empty_arr[i]);
			dfs(i, cnt + 1);
			visit[i] = false;
			obstacle.pop_back();
		}
	}
}

void solution() {
	// 장애물 3곳 조합 찾기
	visit.assign(empty_arr.size(), false);

	dfs(0, 0);

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