class Solution {
public:
	vector<string> extract(string s) {
		vector<string> v;

		string temp;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == '|') {
				v.push_back(temp);
				temp = "";
			}
			else {
				temp += s[i];
			}
		}

		if (!temp.empty()) {
			v.push_back(temp);
		}

		return v;
	}

	int countAsterisks(string s) {
		int answer = 0;
		vector<string> words = extract(s);

		for (int i = 0; i < words.size(); i++) {
			if (i % 2 != 0) {
				continue;
			}

			for (int j = 0; j < words[i].length(); j++) {
				if (words[i][j] == '*') {
					answer++;
				}
			}
		}

		return answer;
	}
};