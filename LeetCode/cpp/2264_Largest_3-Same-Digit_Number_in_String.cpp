class Solution {
public:
	string largestGoodInteger(string num) {
		string answer = "";
		vector<string> goodIntegers;

		string s;
		for (int i = 0; i < 3; i++) {
			s += num[i];
		}

		if (s[0] == s[1] && s[1] == s[2]) {
			goodIntegers.push_back(s);
		}

		for (int i = 3; i < num.length(); i++) {
			s.erase(0, 1);
			s += num[i];

			if (s[0] == s[1] && s[1] == s[2]) {
				goodIntegers.push_back(s);
			}
		}

		if (goodIntegers.size() > 0) {
			sort(goodIntegers.begin(), goodIntegers.end());
			answer = goodIntegers[goodIntegers.size() - 1];
		}

		return answer;
	}
};