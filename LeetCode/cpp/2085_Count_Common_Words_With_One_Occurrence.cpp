class Solution {
public:
	int countWords(vector<string>& words1, vector<string>& words2) {
		unordered_map<string, int> um1, um2;
		int answer = 0;

		for (int i = 0; i < words1.size(); i++) {
			um1[words1[i]]++;
		}

		for (int i = 0; i < words2.size(); i++) {
			um2[words2[i]]++;
		}

		for (auto pair : um1) {
			if (pair.second == 1) {
				if (um2[pair.first] == 1)
					answer++;
			}
		}

		return answer;
	}
};