class Solution {
public:
	int maxSum(vector<int>& nums) {
		int answer = -1;

		unordered_map<int, vector<int>> um;

		for (int n : nums) {
			string s = to_string(n);

			int maxDigit = 0;
			for (int i = 0; i < s.length(); i++) {
				if (maxDigit < (s[i] - '0')) {
					maxDigit = s[i] - '0';
				}
			}

			um[maxDigit].push_back(n);
		}

		for (auto m : um) {
			if (m.second.size() == 1) {
				continue;
			}

			vector<int> v = m.second;

			sort(v.begin(), v.end());

			answer = max(answer, v[v.size() - 1] + v[v.size() - 2]);
		}

		return answer;
	}
};