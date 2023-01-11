class Solution {
public:
	vector<string> makePairs(int n) {
		char pairs[5][2] = { {'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'} };

		vector<string> v;

		if (n == 0) {
			v.push_back("");
			return v;
		}

		if (n == 1) {
			v.push_back("0");
			v.push_back("1");
			v.push_back("8");

			return v;
		}

		vector<string> temp = makePairs(n - 2);
		vector<string> answer;

		for (string t : temp) {
			for (int i = 0; i < 5; i++) {
				string s;
				s = pairs[i][0] + t + pairs[i][1];

				answer.push_back(s);
			}
		}

		return answer;
	}

	vector<string> findStrobogrammatic(int n) {
		vector<string> answer = makePairs(n);

		if (n == 1) {
			return answer;
		}

		priority_queue<string, vector<string>, greater<>> lo;

		for (string s : answer) {
			lo.push(s);
		}

		while (!lo.empty()) {
			string s = lo.top();
			if (s[0] == '0') {
				lo.pop();
			}
			else {
				break;
			}
		}

		answer.clear();

		while (!lo.empty()) {
			answer.push_back(lo.top());
			lo.pop();
		}

		return answer;
	}
};