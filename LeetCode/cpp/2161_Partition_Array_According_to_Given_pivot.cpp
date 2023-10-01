class Solution {
public:
	vector<int> pivotArray(vector<int>& nums, int pivot) {
		vector<int> answer;

		vector<int> sm, sa, lg;

		for (int num : nums) {
			if (num == pivot) {
				sa.push_back(num);
			}
			else if (num < pivot) {
				sm.push_back(num);
			}
			else {
				lg.push_back(num);
			}
		}

		for (int n : sm) {
			answer.push_back(n);
		}

		for (int n : sa) {
			answer.push_back(n);
		}

		for (int n : lg) {
			answer.push_back(n);
		}

		return answer;
	}
};