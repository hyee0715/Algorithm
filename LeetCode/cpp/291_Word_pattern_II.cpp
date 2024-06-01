class Solution {
public:
	vector<int> idxs, v;
	vector<bool> visit;
	unordered_map<char, string> um1;
	unordered_map<string, char> um2;
	set<string> st;
	bool answerFlag;

	vector<string> splitWords(string s) {
		vector<string> ret;

		string temp = s.substr(0, v[0] + 1);
		ret.push_back(temp);

		for (int i = 1; i < v.size() - 1; i++) {
			string temp = s.substr(v[i], v[i + 1] - v[i]);
			ret.push_back(temp);
		}

		temp = s.substr(v[v.size() - 1], s.length() - v[v.size() - 1]);
		ret.push_back(temp);

		return ret;
	}

	bool check(string pattern, string s) {
		vector<string> words = splitWords(s);

		for (int i = 0; i < pattern.length(); i++) {
			if (um1.count(pattern[i]) == 0) {
				if (um2.count(words[i]) == 0) {
					um1[pattern[i]] = words[i];
					um2[words[i]] = pattern[i];
				}
				else {
					return false;
				}
			}
			else {
				string mapWord = um1[pattern[i]];

				if (mapWord != words[i]) {
					return false;
				}
			}
		}

		return true;
	}

	void dfs(int idx, int cnt, string pattern, string s) {
		if (cnt == pattern.length()) {
			um1.clear();
			um2.clear();

			if (check(pattern, s)) {
				answerFlag = true;
			}

			return;
		}

		for (int i = idx; i < idxs.size(); i++) {
			if (visit[i] == true) {
				continue;
			}

			visit[i] = true;
			v.push_back(idxs[i]);
			dfs(i, cnt + 1, pattern, s);
			v.pop_back();
			visit[i] = false;
		}
	}

	bool wordPatternMatch(string pattern, string s) {
		for (int i = 0; i < s.length(); i++) {
			idxs.push_back(i);
		}

		visit.assign(idxs.size(), false);
		answerFlag = false;

		//조합, pattern.length()만큼 뽑기
		dfs(0, 0, pattern, s);

		return answerFlag;
	}
};