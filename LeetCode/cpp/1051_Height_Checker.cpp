class Solution {
public:
	int heightChecker(vector<int>& heights) {
		int answer = 0;
		vector<int> expected;

		for (int n : heights) {
			expected.push_back(n);
		}

		sort(expected.begin(), expected.end());

		for (int i = 0; i < heights.size(); i++) {
			if (heights[i] != expected[i]) {
				answer++;
			}
		}

		return answer;
	}
};