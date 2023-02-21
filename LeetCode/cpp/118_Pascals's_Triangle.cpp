class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> nums;

		for (int i = 0; i < numRows; i++) {
			vector<int> v;

			for (int j = 0; j <= i; j++) {
				v.push_back(0);
			}

			nums.push_back(v);
		}

		for (int i = 0; i < numRows; i++) {
			nums[i][0] = 1;
			nums[i][i] = 1;
		}

		for (int i = 2; i < nums.size(); i++) {
			for (int j = 1; j < nums[i].size() - 1; j++) {
				nums[i][j] = nums[i - 1][j - 1] + nums[i - 1][j];
			}
		}

		return nums;
	}
};