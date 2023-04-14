#include <vector>

using namespace std;

int MOD = 20170805;

int dx[] = { 0, 1 }; //오른쪽 0, 아래 1
int dy[] = { 1, 0 };

int dfs(vector<vector<int>>& city_map, vector<vector<bool>>& visit, int endX, int endY, int dir, int x, int y, vector<vector<vector<int>>>& memo) {
	if (x == endX && y == endY) {
		return 1;
	}

	if (memo[x][y][dir] != -1) {
		return memo[x][y][dir];
	}

	memo[x][y][dir] = 0;

	if (city_map[x][y] == 0) { // 자동차 자유롭게 통행
		for (int i = 0; i < 2; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= city_map.size() || ny >= city_map[0].size()) {
				continue;
			}

			if (city_map[nx][ny] != 1 && visit[nx][ny] == false) {
				visit[nx][ny] = true;
				memo[x][y][dir] += (dfs(city_map, visit, endX, endY, i, nx, ny, memo)) % MOD;
				visit[nx][ny] = false;
			}
		}
	}

	if (city_map[x][y] == 2) { //이전 방향대로만 이동 가능
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx >= 0 && ny >= 0 && nx < city_map.size() && ny < city_map[0].size()) {
			if (city_map[nx][ny] != 1 && visit[nx][ny] == false) {
				visit[nx][ny] = true;
				memo[x][y][dir] += (dfs(city_map, visit, endX, endY, dir, nx, ny, memo)) % MOD;
				visit[nx][ny] = false;
			}
		}
	}

	return memo[x][y][dir] % MOD;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
	int answer = 0;

	vector<vector<bool>> visit(city_map.size(), vector<bool>(city_map[0].size(), false));
	vector<vector<vector<int>>> memo(city_map.size(), vector<vector<int>>(city_map[0].size(), vector<int>(2, -1)));

	answer = dfs(city_map, visit, m - 1, n - 1, 0, 0, 0, memo);

	return answer;
}