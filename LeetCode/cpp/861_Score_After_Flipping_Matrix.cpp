class Solution {
public:
	void rowToggle(vector<vector<int>>& grid, int rowNum) {
		for (int i = 0; i < grid[rowNum].size(); i++) {
			if (grid[rowNum][i] == 1) {
				grid[rowNum][i] = 0;
			}
			else {
				grid[rowNum][i] = 1;
			}
		}
	}

	void colToggle(vector<vector<int>>& grid, int colNum) {
		for (int i = 0; i < grid.size(); i++) {
			if (grid[i][colNum] == 1) {
				grid[i][colNum] = 0;
			}
			else {
				grid[i][colNum] = 1;
			}
		}
	}

	int calculate(vector<vector<int>>& grid) {
		int sum = 0;

		for (vector<int> v : grid) {
			int square = 0;
			int num = 0;

			for (int i = v.size() - 1; i >= 0; i--) {
				if (v[i] == 0) {
					square++;
					continue;
				}

				num += pow(2, square);
				square++;
			}

			sum += num;
		}

		return sum;
	}

	int matrixScore(vector<vector<int>>& grid) {
		//행은 가장 왼쪽의 수가 0이면 토글
		//열은 0의 개수가 1의 개수보다 많으면 토글

		for (int i = 0; i < grid.size(); i++) {
			if (grid[i][0] == 0) {
				rowToggle(grid, i);
			}
		}

		for (int j = 0; j < grid[0].size(); j++) {
			int zeroCnt = 0, oneCnt = 0;

			for (int i = 0; i < grid.size(); i++) {
				if (grid[i][j] == 0) {
					zeroCnt++;
				}
				else {
					oneCnt++;
				}
			}

			if (zeroCnt > oneCnt) {
				colToggle(grid, j);
			}
		}

		return calculate(grid);
	}
};