class Solution {
public:
	bool check(int num, string str) {
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '0') {
				return false;
			}

			int n = str[i] - '0';
			if (num % n != 0) {
				return false;
			}
		}

		return true;
	}

	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> answer;

		for (int i = left; i <= right; i++) {
			string num = to_string(i);

			if (check(i, num)) {
				answer.push_back(i);
			}
		}

		return answer;
	}
};