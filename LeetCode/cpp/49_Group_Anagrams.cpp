class Solution {
public:
	string makeString(map<char, int>& mp) {
		string s;

		for (pair<char, int> p : mp) {
			while (p.second > 0) {
				s += p.first;
				p.second--;
			}
		}

		return s;
	}

	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> answer;
		unordered_map<string, vector<string>> um;

		for (int i = 0; i < strs.size(); i++) {
			map<char, int> mp;

			for (int j = 0; j < strs[i].length(); j++) {
				mp[strs[i][j]]++;
			}

			string s = makeString(mp);

			um[s].push_back(strs[i]);
		}

		for (auto m : um) {
			answer.push_back(m.second);
		}

		return answer;
	}
};