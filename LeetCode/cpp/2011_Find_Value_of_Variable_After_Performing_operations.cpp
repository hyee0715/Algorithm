class Solution {
public:
	int finalValueAfterOperations(vector<string>& operations) {
		int answer = 0;

		for (string operation : operations) {
			if (operation[0] == '+' || operation[operation.length() - 1] == '+') {
				answer++;
				continue;
			}

			if (operation[0] == '-' || operation[operation.length() - 1] == '-') {
				answer--;
			}
		}

		return answer;
	}
};