class Solution {
public:
	vector<vector<int>> largeGroupPositions(string s) {
		vector<vector<int>> answer;

		int start = 0;
		int end = 0;

		while (start <= end && end < s.length()) {
			if (s[start] == s[end]) {
				end++;
				continue;
			}

			if (end == s.length()) {
				break;
			}

			if (s[start] != s[end]) {
				if (end - start >= 3) {
					answer.push_back({ start, end - 1 });
				}

				start = end;
			}
		}

		if (end - start >= 3) {
			answer.push_back({ start, end - 1 });
		}

		return answer;
	}
};