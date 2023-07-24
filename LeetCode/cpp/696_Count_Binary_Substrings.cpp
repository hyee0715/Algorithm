class Solution {
public:
	int countBinarySubstrings(string s) {
		int answer = 0;
		vector<int> nums;

		int cnt = 1;

		for (int i = 0; i < s.length() - 1; i++) {
			if (s[i] == s[i + 1]) {
				cnt++;
				continue;
			}

			nums.push_back(cnt);
			cnt = 1;
		}

		nums.push_back(cnt);

		for (int i = 0; i < nums.size() - 1; i++) {
			answer += min(nums[i], nums[i + 1]);
		}

		return answer;
	}
};