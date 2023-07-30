class Solution {
public:
	vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
		vector<string> answer;

		string s;
		for (int i = 0; i < words.size(); i++) {
			for (int j = 0; j < words[i].length(); j++) {
				if (words[i][j] == separator) {
					if (!s.empty()) {
						answer.push_back(s);
						s.clear();
					}
				}
				else {
					s += words[i][j];
				}
			}

			if (!s.empty()) {
				answer.push_back(s);
				s.clear();
			}
		}

		return answer;
	}
};