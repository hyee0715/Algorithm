class Solution {
public:
	int canBeTypedWords(string text, string brokenLetters) {
		unordered_map<char, int> um;
		vector<string> v;
		string s;
		int answer = 0;

		for (int i = 0; i < brokenLetters.size(); i++) {
			um[brokenLetters[i]]++;
		}

		for (int i = 0; i < text.size(); i++) {
			if (text[i] == ' ') {
				v.push_back(s);
				s.clear();
			}
			else {
				s += text[i];
			}
		}

		v.push_back(s);
		s.clear();

		for (int i = 0; i < v.size(); i++) {
			bool flag = false;

			for (int j = 0; j < v[i].size(); j++) {
				if (um[v[i][j]] != 0) {
					flag = true;
					break;
				}
			}

			if (!flag) {
				answer++;
			}
		}

		return answer;
	}
};