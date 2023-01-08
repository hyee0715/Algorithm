class Solution {
public:
	int calculateSum(vector<int>& v) {
		int sum = 0;

		for (int n : v) {
			sum += n;
		}

		return sum;
	}

	void check(int idx, int cnt, vector<int>& candidates, int target, vector<int>& v, vector<vector<int>>& answer) {
		if (calculateSum(v) == target) {
			answer.push_back(v);
			return;
		}

		if (calculateSum(v) > target) {
			return;
		}

		for (int i = idx; i < candidates.size(); i++) {
			v.push_back(candidates[i]);
			check(i, cnt + 1, candidates, target, v, answer);
			v.pop_back();
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> answer;
		vector<int> v;

		check(0, 0, candidates, target, v, answer);

		return answer;
	}
};