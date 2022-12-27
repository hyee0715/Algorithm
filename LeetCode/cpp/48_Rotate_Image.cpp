class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int totalSize = matrix[0].size() * matrix.size();
		vector<int> v(totalSize, 0);

		int size = matrix.size();
		int idx = size - 1;
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[i].size(); j++) {
				v[idx + (size * j)] = matrix[i][j];
			}
			idx--;
		}

		int temp_idx = 0;
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[i].size(); j++) {
				matrix[i][j] = v[temp_idx];
				temp_idx++;
			}
		}
	}
};