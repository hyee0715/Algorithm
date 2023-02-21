class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> answer;
		vector<vector<int>> nums;

		for (int i = 0; i < rowIndex + 1; i++) {
			vector<int> v;

			for (int j = 0; j <= i; j++) {
				v.push_back(0);
			}

			nums.push_back(v);
		}

		for (int i = 0; i <= rowIndex; i++) {
			nums[i][0] = 1;
			nums[i][i] = 1;
		}

		for (int i = 2; i < nums.size(); i++) {
			for (int j = 1; j < nums[i].size() - 1; j++) {
				nums[i][j] = nums[i - 1][j - 1] + nums[i - 1][j];
			}
		}

		for (int i = 0; i < nums.size(); i++) {
			answer.push_back(nums[nums.size() - 1][i]);
		}

		return answer;
	}
};