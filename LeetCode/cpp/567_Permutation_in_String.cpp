class Solution {
public:
	bool isSame(vector<int> v1, vector<int> v2) {
		for (int i = 0; i < v1.size(); i++) {
			if (v1[i] != v2[i]) {
				return false;
			}
		}

		return true;
	}

	bool checkInclusion(string s1, string s2) {
		if (s1.length() > s2.length()) {
			return false;
		}

		vector<int> v1(26, 0), v2(26, 0);

		for (int i = 0; i < s1.length(); i++) {
			v1[s1[i] - 'a']++;
		}

		for (int i = 0; i < s1.length(); i++) {
			v2[s2[i] - 'a']++;
		}

		int left = 0, right = s1.length() - 1;

		while (right < s2.length()) {
			if (isSame(v1, v2)) {
				return true;
			}

			v2[s2[left] - 'a']--;
			left++;
			right++;

			if (right == s2.length()) {
				break;
			}

			v2[s2[right] - 'a']++;
		}

		return false;
	}
};