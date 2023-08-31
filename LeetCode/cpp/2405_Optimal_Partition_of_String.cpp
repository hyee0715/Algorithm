class Solution {
public:
	int partitionString(string s) {
		int answer = 0;

		unordered_map<char, int> um;

		for (int i = 0; i < s.length(); i++) {
			if (um[s[i]] > 0) {
				answer++;
				um.clear();
			}

			um[s[i]]++;
		}

		for (auto m : um) {
			if (m.second > 0) {
				answer++;
				break;
			}
		}

		return answer;
	}
};