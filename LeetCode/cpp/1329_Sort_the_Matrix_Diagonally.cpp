class Solution {
public:
	vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
		map<pair<int, int>, vector<int>> um;

		for (int i = 0; i < mat.size(); i++) {
			for (int j = 0; j < mat[0].size(); j++) {
				if (i <= j) {
					um[{i - i, j - i}].push_back(mat[i][j]);
				}
				else {
					um[{i - j, j - j}].push_back(mat[i][j]);
				}
			}
		}

		for (auto m : um) {
			vector<int> v = m.second;

			sort(v.begin(), v.end());

			int x = m.first.first;
			int y = m.first.second;

			for (int i = 0; i < v.size(); i++) {
				mat[x][y] = v[i];

				x++;
				y++;
			}
		}

		return mat;
	}
};