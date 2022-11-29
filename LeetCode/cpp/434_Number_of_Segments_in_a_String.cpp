class Solution {
public:
	int countSegments(string s) {
		vector<string> v;

		string temp;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				if (temp.size() == 0) {
					continue;
				}

				v.push_back(temp);
				temp.clear();
			}
			else {
				temp += s[i];
			}
		}

		if (!temp.empty()) {
			v.push_back(temp);
		}

		return v.size();
	}
};