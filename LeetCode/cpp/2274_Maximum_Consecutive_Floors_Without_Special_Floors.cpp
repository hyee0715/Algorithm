class Solution {
public:
	int maxConsecutive(int bottom, int top, vector<int>& special) {
		int answer = 0;

		sort(special.begin(), special.end());

		for (int i = 0; i < special.size() - 1; i++) {
			answer = max(answer, special[i + 1] - special[i] - 1);
		}

		answer = max(answer, special[0] - bottom);
		answer = max(answer, top - special[special.size() - 1]);

		return answer;
	}
};