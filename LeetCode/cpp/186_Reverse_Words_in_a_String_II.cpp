class Solution {
public:
	void reverseWords(vector<char>& s) {
		vector<string> v;
		string str = "";

		for (int i = 0; i < s.size(); i++) {
			if (s[i] != ' ') {
				str += s[i];
			}
			else {
				v.push_back(str);
				str = "";
			}
		}

		v.push_back(str);
		reverse(v.begin(), v.end());

		s.clear();

		for (int i = 0; i < v.size(); i++) {

			for (int j = 0; j < v[i].size(); j++) {
				s.push_back(v[i][j]);
			}
			s.push_back(' ');
		}

		s.pop_back();
	}
};