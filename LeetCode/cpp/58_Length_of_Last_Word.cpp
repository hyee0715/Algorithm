class Solution {
public:
	int lengthOfLastWord(string s) {
		vector<string> v;
		string temp;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] != ' ')
				temp += s[i];
			else {
				if (temp != "") {
					v.push_back(temp);
					temp.clear();
				}
			}
		}

		if (temp != "")
			v.push_back(temp);

		return v[v.size() - 1].size();
	}
};