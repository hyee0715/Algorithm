class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> answer;
		unordered_map<char, string> phone;

		phone['2'] = "abc";
		phone['3'] = "def";
		phone['4'] = "ghi";
		phone['5'] = "jkl";
		phone['6'] = "mno";
		phone['7'] = "pqrs";
		phone['8'] = "tuv";
		phone['9'] = "wxyz";

		for (int i = 0; i < digits.length(); i++) {
			string s = phone[digits[i]];

			if (answer.empty() && i == 0) {
				for (int j = 0; j < s.length(); j++) {
					string st;
					st += s[j];
					answer.push_back(st);
				}

				continue;
			}

			vector<string> temp;
			int size = answer.size();

			for (string t : answer) {
				temp.push_back(t);
			}

			answer.clear();

			for (int j = 0; j < size; j++) {
				string str = temp[temp.size() - 1];
				temp.pop_back();

				for (int k = 0; k < s.length(); k++) {
					answer.push_back(str + s[k]);
				}
			}
		}

		return answer;
	}
};