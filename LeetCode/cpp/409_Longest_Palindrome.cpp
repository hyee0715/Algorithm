class Solution {
public:
	int longestPalindrome(string s) {
		unordered_map<char, int> um;
		int answer = 0;
		int odd_cnt = 0;

		for (int i = 0; i < s.size(); i++)
			um[s[i]]++;

		for (auto m : um) {
			if (m.second % 2 == 0) {
				answer += m.second;
			}
			else { //m.second % 2 != 0
				if (m.second > 1) {
					answer += (m.second - 1);
					um[m.first] = 1;
				}
			}
		}

		for (auto m : um) {
			if (m.second == 1)
				odd_cnt++;
		}

		if (odd_cnt >= 1)
			answer++;

		return answer;
	}
};