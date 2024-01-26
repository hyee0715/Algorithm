#include <string>
#include <vector>
#include <queue>
#include <set>
#include <unordered_map>

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int bfs(int a, int b, vector<vector<int>>& land, vector<vector<bool>>& visit, set<int>& colSet) {
	int quantity = 0;

	queue<pair<int, int>> q;

	q.push({ a, b });
	visit[a][b] = true;

	colSet.insert(b);

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		quantity++;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= land.size() || ny >= land[0].size()) {
				continue;
			}

			if (land[nx][ny] == 1 && visit[nx][ny] == false) {
				visit[nx][ny] = true;
				q.push({ nx, ny });

				colSet.insert(ny);
			}
		}
	}

	return quantity;
}

void checkCol(set<int>& colSet, unordered_map<int, int>& um, int quantity) {
	for (int col : colSet) {
		um[col] += quantity;
	}
}


int findMaxValue(unordered_map<int, int>& um) {
	int maxNum = -1;

	for (auto m : um) {
		if (m.second > maxNum) {
			maxNum = m.second;
		}
	}

	return maxNum;
}

int solution(vector<vector<int>> land) {
	int answer = 0;

	vector<vector<bool>> visit(land.size(), vector<bool>(land[0].size(), false));
	set<int> colSet;
	unordered_map<int, int> um; //col, 총 석유량

	for (int i = 0; i < land.size(); i++) {
		for (int j = 0; j < land[i].size(); j++) {

			if (land[i][j] == 1 && visit[i][j] == false) {
				colSet.clear();

				int quantity = bfs(i, j, land, visit, colSet);

				checkCol(colSet, um, quantity);
			}
		}
	}

	answer = findMaxValue(um);

	return answer;
}