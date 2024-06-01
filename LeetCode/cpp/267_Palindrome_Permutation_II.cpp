class Solution {
public:
	unordered_map<char, int> um;
	vector<char> chars, v;
	vector<bool> visit;
	set<string> st;

	bool validateMap() {
		bool flag = false;

		for (pair<char, int> p : um) {
			if (p.second % 2 != 0) {
				if (!flag) {
					flag = true;
				}
				else {
					return false;
				}
			}
		}

		return true;
	}

	void dfs(int cnt, string s, char oddChar) {
		if (cnt == chars.size()) {
			string temp = "", rev = "", result = "";

			for (int i = 0; i < v.size(); i++) {
				temp += v[i];
			}

			rev = temp;
			reverse(rev.begin(), rev.end());

			if (oddChar == '*') {
				result = temp + rev;
			}
			else {
				result = temp + oddChar + rev;
			}

			st.insert(result);

			return;
		}

		for (int i = 0; i < chars.size(); i++) {
			if (visit[i] == true) {
				continue;
			}

			visit[i] = true;
			v.push_back(chars[i]);
			dfs(cnt + 1, s, oddChar);
			v.pop_back();
			visit[i] = false;
		}
	}

	vector<string> generatePalindromes(string s) {
		vector<string> answer;

		for (int i = 0; i < s.length(); i++) {
			um[s[i]]++;
		}

		if (!validateMap()) {
			return answer;
		}

		char oddCntChar = '*';
		for (pair<char, int> p : um) {
			if (p.second % 2 != 0) {
				oddCntChar = p.first;
			}

			for (int i = 0; i < p.second / 2; i++) {
				chars.push_back(p.first);
			}
		}

		visit.assign(chars.size(), false);

		dfs(0, s, oddCntChar);

		for (string ss : st) {
			answer.push_back(ss);
		}

		return answer;
	}
};