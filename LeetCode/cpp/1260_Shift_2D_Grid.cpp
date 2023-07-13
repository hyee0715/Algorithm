class Solution {
public:
	vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
		vector<vector<int>> answer(grid.size(), vector<int>(grid[0].size()));

		vector<int> v;
		for (vector<int> g : grid) {
			for (int n : g) {
				v.push_back(n);
			}
		}

		while (k > 0) {
			int prev = v[v.size() - 1];
			int temp;
			for (int i = 0; i < v.size() - 1; i++) {
				temp = v[i];
				v[i] = prev;
				prev = temp;
			}

			v[v.size() - 1] = prev;

			k--;
		}

		int row = 0;
		int col = 0;

		for (int i = 0; i < v.size(); i++) {
			if (col == answer[0].size()) {
				col = 0;
				row++;
			}

			answer[row][col] = v[i];
			col++;
		}

		return answer;
	}
};