class Solution {
public:
	int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
		int answer = 0;

		int rule = 2;
		if (ruleKey == "type") {
			rule = 0;
		}
		else if (ruleKey == "color") {
			rule = 1;
		}

		for (vector<string> item : items) {
			if (item[rule] == ruleValue) {
				answer++;
			}
		}

		return answer;
	}
};