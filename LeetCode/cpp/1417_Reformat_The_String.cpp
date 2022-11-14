class Solution {
public:
	string reformat(string s) {
		string answer;
		vector<char> v1, v2;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= '0' && s[i] <= '9') {
				v1.push_back(s[i]);
				continue;
			}

			if (s[i] >= 'a' && s[i] <= 'z') {
				v2.push_back(s[i]);
			}
		}

		if (v1.size() == 0 && v2.size() == 1) {
			answer += v2[0];
			return answer;
		}

		if (v1.size() == 1 && v2.size() == 0) {
			answer += v1[0];
			return answer;
		}

		if (v1.size() > v2.size() && v1.size() - v2.size() >= 2) {
			return answer;
		}

		if (v2.size() > v1.size() && v2.size() - v1.size() >= 2) {
			return answer;
		}

		if (v1.size() > v2.size()) {
			for (int i = 0; i < v2.size(); i++) {
				answer += v1[i];
				answer += v2[i];
			}

			answer += v1[v1.size() - 1];
		}

		if (v2.size() > v1.size()) {
			for (int i = 0; i < v1.size(); i++) {
				answer += v2[i];
				answer += v1[i];
			}

			answer += v2[v2.size() - 1];
		}

		if (v1.size() == v2.size()) {
			for (int i = 0; i < v1.size(); i++) {
				answer += v1[i];
				answer += v2[i];
			}
		}

		return answer;
	}
};