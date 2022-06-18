class Solution {
public:
	string capitalizeTitle(string title) {
		vector<string> v;
		string s, answer = "";
		bool first_letter;

		for (int i = 0; i < title.size(); i++) {
			if (title[i] != ' ') {
				s = s + title[i];
			}
			else {
				v.push_back(s);
				s = "";
			}
		}

		if (!s.empty()) {
			v.push_back(s);
			s = "";
		}

		for (int i = 0; i < v.size(); i++) {
			first_letter = true;

			if (v[i].size() <= 2) {
				for (int j = 0; j < v[i].size(); j++) {
					v[i][j] = tolower(v[i][j]);
					answer = answer + v[i][j];
				}
			}
			else {
				for (int j = 0; j < v[i].size(); j++) {
					if (first_letter) {
						v[i][j] = toupper(v[i][j]);
						answer = answer + v[i][j];
						first_letter = false;
					}
					else {
						v[i][j] = tolower(v[i][j]);
						answer = answer + v[i][j];
					}
				}
			}

			if (i != v.size() - 1)
				answer += " ";
		}

		return answer;
	}
};