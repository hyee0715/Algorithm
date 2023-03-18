class Solution {
public:
	int rearrangeCharacters(string s, string target) {
		int answer = 100;
		unordered_map<char, int> um, um2;

		for (int i = 0; i < s.length(); i++) {
			um[s[i]]++;
		}

		for (int i = 0; i < target.length(); i++) {
			um2[target[i]]++;
		}

		for (auto m : um2) {
			answer = min(answer, um[m.first] / m.second);
		}

		return answer;
	}
};