class Solution {
public:
	vector<int> minOperations(string boxes) {
		vector<int> answer(boxes.length(), 0);

		for (int i = 0; i < answer.size(); i++) {
			for (int j = 0; j < boxes.length(); j++) {
				if (boxes[j] == '1') {
					answer[i] += abs(i - j);
				}
			}
		}

		return answer;
	}
};