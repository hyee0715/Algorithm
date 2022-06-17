class Solution {
public:
	string reverseWords(string s) {
		string answer = "";
		string temp = "";

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				reverse(temp.begin(), temp.end());
				answer = answer + temp + " ";
				temp = "";
				continue;
			}

			temp += s[i];
		}

		if (!temp.empty()) {
			reverse(temp.begin(), temp.end());
			answer = answer + temp;
		}

		return answer;
	}
};