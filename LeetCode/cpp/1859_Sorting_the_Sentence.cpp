class Solution {
public:
	string sortSentence(string s) {
		vector<pair<int, string>> v;
		string answer, temp;
		int num;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				pair<int, string> p = { num, temp };
				v.push_back(p);
				temp.clear();
			}
			else if (s[i] >= '0' && s[i] <= '9') {
				num = s[i] - '0';
			}
			else {
				temp += s[i];
			}
		}

		pair<int, string> p = { num, temp };
		v.push_back(p);

		sort(v.begin(), v.end());

		for (int i = 0; i < v.size(); i++) {
			answer += v[i].second;

			if (i != v.size() - 1)
				answer += ' ';
		}

		return answer;
	}
};