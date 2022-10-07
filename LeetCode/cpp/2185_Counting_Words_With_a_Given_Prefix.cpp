class Solution {
public:
	int prefixCount(vector<string>& words, string pref) {
		int answer = 0;

		for (int i = 0; i < words.size(); i++) {
			int idx = 0;

			for (int j = 0; j < words[i].size(); j++) {
				if (words[i][j] == pref[idx]) {
					idx++;

					if (idx == pref.size()) {
						answer++;
						break;
					}

				}
				else {
					break;
				}
			}
		}

		return answer;
	}
};