class Solution {
public:
	vector<string> divideString(string s, int k, char fill) {
		vector<string> answer;

		int cnt = 0;
		string temp;

		for (int i = 0; i < s.length(); i++) {
			if (cnt == k) {
				cnt = 0;
				answer.push_back(temp);
				temp.clear();
			}

			temp += s[i];
			cnt++;
		}

		if (!temp.empty()) {
			while (temp.length() < k) {
				temp += fill;
			}

			answer.push_back(temp);
		}

		return answer;
	}
};