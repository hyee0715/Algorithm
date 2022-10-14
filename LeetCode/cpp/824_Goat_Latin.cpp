class Solution {
public:
	string toGoatLatin(string sentence) {
		string answer, s;
		vector<string> v;

		for (int i = 0; i < sentence.size(); i++) {
			if (sentence[i] == ' ') {
				v.push_back(s);
				s.clear();
			}
			else {
				s += sentence[i];
			}
		}

		if (!s.empty()) {
			v.push_back(s);
		}

		for (int i = 0; i < v.size(); i++) {
			s.clear();

			if (v[i][0] != 'a' && v[i][0] != 'i' && v[i][0] != 'u' && v[i][0] != 'e' && v[i][0] != 'o' && v[i][0] != 'A' && v[i][0] != 'I' && v[i][0] != 'U' && v[i][0] != 'E' && v[i][0] != 'O') {
				for (int j = 1; j < v[i].size(); j++) {
					s += v[i][j];
				}

				s += v[i][0];

				v[i] = s;
			}
		}

		for (int i = 0; i < v.size(); i++) {
			answer += v[i];
			answer += "ma";

			for (int j = 0; j <= i; j++) {
				answer += "a";
			}

			if (i != (v.size() - 1))
				answer += ' ';
		}

		return answer;
	}
};