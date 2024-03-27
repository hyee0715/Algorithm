#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int r, c, k;
vector<vector<int>> board(3, vector<int>(3));
vector<pair<int, int>> rNums, cNums;
vector<vector<int>> totalRows, totalColumns;

void input() {
	cin >> r >> c >> k;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> board[i][j];
		}
	}
}

unordered_map<int, int> settingMap(int row) {
	unordered_map<int, int> map;

	vector<int> v = board[row];

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == 0) continue;

		map[v[i]]++;
	}

	return map;
}

vector<pair<int, int>> settingMapToNums(unordered_map<int, int>& map) {
	vector<pair<int, int>> nums;

	for (pair<int, int> mp : map) {
		nums.push_back({ mp.second, mp.first });
	}

	sort(nums.begin(), nums.end());

	return nums;
}

vector<int> convertRow(vector<pair<int, int>>& nums) {
	vector<int> v;

	for (pair<int, int> num : nums) {
		v.push_back(num.second);
		v.push_back(num.first);
	}

	return v;
}

int findMaxCol(vector<vector<int>>& total) {
	int maxCol = 0;

	for (vector<int> row : total) {
		int rowSize = row.size();
		maxCol = max(maxCol, rowSize);
	}

	return maxCol;
}

vector<vector<int>> rotate() {
	vector<vector<int>> ret(board[0].size(), vector<int>(board.size(), 0));

	int x = 0, y = 0;

	for (int j = 0; j < board[0].size(); j++) {
		for (int i = 0; i < board.size(); i++) {
			ret[x][y] = board[i][j];
			y++;
		}

		x++;
		y = 0;
	}

	return ret;
}

void solution() {
	int seconds = 0;

	while (1) {
		if (seconds == 101) {
			seconds = -1;
			break;
		}

		if (r - 1 < board.size() && c - 1 < board[0].size() && board[r - 1][c - 1] == k) {
			break;
		}

		if (board.size() >= board[0].size()) {
			vector<vector<int>> total;

			for (int rowNum = 0; rowNum < board.size(); rowNum++) {
				unordered_map<int, int> rMap = settingMap(rowNum);

				vector<pair<int, int>> nums = settingMapToNums(rMap);

				vector<int> row = convertRow(nums);

				total.push_back(row);
			}

			int maxCol = findMaxCol(total);
			
			board.clear();
			board.assign(total.size(), vector<int>(maxCol, 0));

			for (int i = 0; i < total.size(); i++) {
				for (int j = 0; j < total[i].size(); j++) {
					board[i][j] = total[i][j];
				}
			}
		}
		else {
			vector<vector<int>> tempBoard = rotate();

			board.clear();
			board.assign(tempBoard.size(), vector<int>(tempBoard[0].size()));

			for (int i = 0; i < tempBoard.size(); i++) {
				for (int j = 0; j < tempBoard[i].size(); j++) {
					board[i][j] = tempBoard[i][j];
				}
			}

			vector<vector<int>> total;

			for (int rowNum = 0; rowNum < board.size(); rowNum++) {
				unordered_map<int, int> cMap = settingMap(rowNum);

				vector<pair<int, int>> nums = settingMapToNums(cMap);

			
				vector<int> row = convertRow(nums);

				total.push_back(row);
			}

			int maxRow = findMaxCol(total);

			board.clear();
			board.assign(maxRow, vector<int>(total.size(), 0));

			int x = 0, y = 0;
			for (int i = 0; i < total.size(); i++) {
				for (int j = 0; j < total[i].size(); j++) {
					board[x][y] = total[i][j];
					x++;
				}

				y++;
				x = 0;
			}
		}

		seconds++;
	}

	cout << seconds;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();
	solution();

	return 0;
}