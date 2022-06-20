class Solution {
public:
	vector<string> uncommonFromSentences(string s1, string s2) {
		unordered_map<string, int> um;
		vector<string> answer;
		string str = "";

		for (auto s : s1) {
			if (s != ' ')
				str += s;
			else {
				um[str]++;
				str.clear();
			}
		}

		um[str]++;
		str.clear();

		for (auto s : s2) {
			if (s != ' ')
				str += s;
			else {
				um[str]++;
				str.clear();
			}
		}

		um[str]++;
		str.clear();

		for (auto pair : um) {
			if (pair.second == 1) {
				answer.push_back(pair.first);
			}
		}

		return answer;
	}
};