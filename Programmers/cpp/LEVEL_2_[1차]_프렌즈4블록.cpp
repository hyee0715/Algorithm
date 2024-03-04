#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<vector<char>> settingMap(vector<string>& board) {
	vector<vector<char>> map;

	for (string s : board) {
		vector<char> v;

		for (int i = 0; i < s.length(); i++) {
			v.push_back(s[i]);
		}

		map.push_back(v);
	}

	return map;
}

void findSameFourBlocks(vector<vector<char>>& map, queue<pair<int, int>>& q) {
	for (int i = 0; i < map.size() - 1; i++) {
		for (int j = 0; j < map[i].size() - 1; j++) {
			if (map[i][j] != '*' && map[i][j] == map[i + 1][j] && map[i][j] == map[i][j + 1] && map[i][j] == map[i + 1][j + 1]) {
				q.push({ i, j });
				q.push({ i + 1, j });
				q.push({ i, j + 1 });
				q.push({ i + 1, j + 1 });
			}
		}
	}
}

void deleteBlocks(vector<vector<char>>& map, queue<pair<int, int>>& q) {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (map[x][y] != '*') {
			map[x][y] = '*';
		}
	}
}

void dropBlock(vector<vector<char>>& map, int column) {
	queue<char> q;

	for (int i = map.size() - 1; i >= 0; i--) {
		if (map[i][column] != '*') {
			q.push(map[i][column]);
		}
	}

	int qSize = q.size();
	int row = map.size() - 1;

	while (!q.empty()) {
		map[row][column] = q.front();

		row--;
		q.pop();
	}

	for (int i = 0; i < map.size() - qSize; i++) {
		map[i][column] = '*';
	}
}

void dropBlocks(vector<vector<char>>& map) {
	for (int j = 0; j < map[0].size(); j++) {
		dropBlock(map, j);
	}
}

int countDeletedBlocks(vector<vector<char>>& map) {
	int cnt = 0;

	for (vector<char> v : map) {
		for (char c : v) {
			if (c == '*') {
				cnt++;
			}
		}
	}

	return cnt;
}

int solution(int m, int n, vector<string> board) {
	int answer = 0;

	vector<vector<char>> map = settingMap(board);
	queue<pair<int, int>> q; //없애야 할 블록 x, y 좌표

	findSameFourBlocks(map, q);

	while (!q.empty()) {
		deleteBlocks(map, q);

		dropBlocks(map);

		findSameFourBlocks(map, q);
	}

	int deletedCnt = countDeletedBlocks(map);
	answer = deletedCnt;

	return answer;
}