class Solution {
public:
	int smallestCommonElement(vector<vector<int>>& mat) {
		map<int, int> um;
		int min_num = INT_MAX;

		for (int i = 0; i < mat.size(); i++) {
			for (int j = 0; j < mat[i].size(); j++) {
				um[mat[i][j]]++;
			}
		}

		for (auto m : um) {
			if (m.second == mat.size())
				min_num = min(min_num, m.first);
		}

		if (min_num == INT_MAX)
			return -1;

		return min_num;
	}
};