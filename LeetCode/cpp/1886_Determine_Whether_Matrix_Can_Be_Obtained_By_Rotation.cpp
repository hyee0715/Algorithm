class Solution {
public:
	bool check(vector<vector<int>>& target, vector<vector<int>> sample) {
		for (int i = 0; i < target.size(); i++) {
			for (int j = 0; j < target[i].size(); j++) {
				if (target[i][j] != sample[i][j]) {
					return false;
				}
			}
		}

		return true;
	}

	bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
		vector<vector<int>> v1(mat.size(), vector<int>(mat.size()));
		vector<vector<int>> v2(mat.size(), vector<int>(mat.size()));
		vector<vector<int>> v3(mat.size(), vector<int>(mat.size()));

		vector<int> temp;
		for (int i = 0; i < mat.size(); i++) {
			temp.clear();
			for (int j = 0; j < mat[i].size(); j++) {
				temp.push_back(mat[i][j]);
			}

			int temp_idx = 0;
			int end_point = mat[i].size() - 1 - i;
			for (int j = 0; j < mat[i].size(); j++) {
				v1[j][end_point] = temp[temp_idx];
				temp_idx++;
			}

			temp_idx = 0;
			end_point = mat[i].size() - 1 - i;
			for (int j = mat[i].size() - 1; j >= 0; j--) {
				v2[end_point][j] = temp[temp_idx];
				temp_idx++;
			}

			temp_idx = 0;
			end_point = i;
			for (int j = mat[i].size() - 1; j >= 0; j--) {
				v3[j][end_point] = temp[temp_idx];
				temp_idx++;
			}
		}

		if (check(target, mat) || check(target, v1) || check(target, v2) || check(target, v3)) {
			return true;
		}

		return false;
	}
};