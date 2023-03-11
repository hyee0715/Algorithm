class Solution {
public:
	bool isDuplicate(unordered_map<char, int> um) {
		for (auto m : um) {
			if (m.second > 1) {
				return true;
			}
		}

		return false;
	}

	int numKLenSubstrNoRepeats(string s, int k) {
		unordered_map<char, int> um;
		int answer = 0;

		if (s.length() < k) {
			return 0;
		}

		for (int i = 0; i < k; i++) {
			um[s[i]]++;
		}

		int left = 0, right = k - 1;

		while (right < s.length()) {
			if (!isDuplicate(um)) {
				answer++;
			}

			um[s[left]]--;
			left++;
			right++;
			um[s[right]]++;
		}

		return answer;
	}
};