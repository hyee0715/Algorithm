class Solution {
public:
	vector<int> getNoZeroIntegers(int n) {
		vector<int> answer;

		for (int i = 1; i < n; i++) {
			if (to_string(i).find('0') != string::npos || to_string(n - i).find('0') != string::npos) {
				continue;
			}

			answer.push_back(i);
			answer.push_back(n - i);
			break;
		}

		return answer;
	}
};