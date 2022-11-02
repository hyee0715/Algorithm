class Solution {
public:
	string reverseWords(string s) {
		vector<string> v;
		string answer;

		while (1) {
			if (s[0] == ' ') {
				s.erase(0, 1);
			}
			else {
				break;
			}
		}

		while (1) {
			if (s[s.size() - 1] == ' ') {
				s.erase(s.size() - 1, 1);
			}
			else {
				break;
			}
		}

		string temp;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				if (!temp.empty()) {
					v.push_back(temp);
					temp.clear();
				}
			}
			else {
				temp += s[i];
			}
		}

		if (!temp.empty()) {
			v.push_back(temp);
			s.clear();
		}

		for (int i = v.size() - 1; i >= 0; i--) {
			answer += v[i];

			if (i != 0)
				answer += " ";
		}

		return answer;
	}
};