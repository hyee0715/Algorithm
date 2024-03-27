#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

int n, m;
vector<vector<int>> board;
vector<bool> visit;
vector<int> v; //조합으로 뽑은 치킨 집 인덱스
vector<pair<int, int>> chickens, houses;
vector<vector<int>> tempBoard;
int answer = INT_MAX;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void input() {
	cin >> n >> m;

	board.assign(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];

			if (board[i][j] == 1) {
				houses.push_back({ i, j });
			}
			else if (board[i][j] == 2) {
				chickens.push_back({ i, j });
			}
		}
	}
}

void settingTempBoard() {
	tempBoard.clear();
	tempBoard.assign(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 2) {
				tempBoard[i][j] = 0;
			}
			else {
				tempBoard[i][j] = board[i][j];
			}
		}
	}

	for (int i = 0; i < v.size(); i++) {
		int idx = v[i];
		
		int x = chickens[idx].first;
		int y = chickens[idx].second;

		tempBoard[x][y] = 2;
	}
}

int findShortestDistance(int x, int y, vector<pair<int, int>>& chicks) {
	int shortestDistance = INT_MAX;
	
	for (int i = 0; i < chicks.size(); i++) {
		int cx = chicks[i].first;
		int cy = chicks[i].second;

		int distance = abs(x - cx) + abs(y - cy);

		shortestDistance = min(shortestDistance, distance);
	}

	return shortestDistance;
}

vector<pair<int, int>> getSelectedChickens() {
	vector<pair<int, int>> ret;

	for (int i = 0; i < v.size(); i++) {
		int idx = v[i];

		ret.push_back(chickens[idx]);
	}

	return ret;
}

int getCityChickenDistance() {
	//도시의 집(=1) 찾을때마다 bfs로 가장 가까운 치킨 집(=2) 찾기
	int shortestCityChickentDistance = 0;

	for (int i = 0; i < tempBoard.size(); i++) {
		for (int j = 0; j < tempBoard.size(); j++) {
			if (tempBoard[i][j] == 1) {
				vector<pair<int, int>> chicks = getSelectedChickens();

				int distance = findShortestDistance(i, j, chicks);
				shortestCityChickentDistance += distance;
			}
		}
	}

	return shortestCityChickentDistance;
}

void dfs(int idx, int cnt) {
	if (cnt == m) {
		settingTempBoard();

		//tempBoard의 도시 치킨 거리 구하기
		int cityDistance = getCityChickenDistance();

		answer = min(answer, cityDistance);

		return;
	}

	for (int i = idx; i < chickens.size(); i++) {
		if (visit[i] == true) continue;
		visit[i] = true;
		v.push_back(i);
		dfs(i, cnt + 1);
		visit[i] = false;
		v.pop_back();
	}
}

void solution() {
	//조합
	visit.assign(chickens.size(), false);

	dfs(0, 0);

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