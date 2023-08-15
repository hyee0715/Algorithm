class Solution {
public:
	vector<string> separate(string str) {
		vector<string> ret;

		string s;
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == ' ') {
				ret.push_back(s);
				ret.push_back(str.substr(i + 1, str.length() - i - 1));
			}
			else {
				s += str[i];
			}
		}

		return ret;
	}

	void extract(vector<string> sep, unordered_map<string, int>& um) {
		int num = stoi(sep[0]);
		string s = sep[1];

		string temp;
		for (int i = s.length() - 1; i >= 0; i--) {
			if (s[i] == '.') {
				um[temp] += num;
			}

			temp = s[i] + temp;
		}

		um[temp] += num;
	}

	vector<string> subdomainVisits(vector<string>& cpdomains) {
		vector<string> answer;
		unordered_map<string, int> um;

		for (string cpdomain : cpdomains) {
			vector<string> sep = separate(cpdomain);

			extract(sep, um);
		}

		for (auto m : um) {
			string s = to_string(m.second) + " " + m.first;
			answer.push_back(s);
		}

		return answer;
	}
};