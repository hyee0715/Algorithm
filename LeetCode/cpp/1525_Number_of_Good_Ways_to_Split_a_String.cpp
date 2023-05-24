class Solution {
public:
	int numSplits(string s) {
		int answer = 0;
		unordered_map<char, int> left, right;

		left[s[0]]++;

		for (int i = 1; i < s.length(); i++) {
			right[s[i]]++;
		}

		if (left.size() == right.size()) {
			answer++;
		}

		for (int i = 1; i < s.length() - 1; i++) {
			right[s[i]]--;
			left[s[i]]++;

			if (right[s[i]] == 0) {
				right.erase(s[i]);
			}

			if (left.size() == right.size()) {
				answer++;
			}
		}

		return answer;
	}
};