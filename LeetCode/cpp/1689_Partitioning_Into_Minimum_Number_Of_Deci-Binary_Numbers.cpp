class Solution {
public:
	int minPartitions(string n) {
		int answer = 0;

		for (int i = 0; i < n.length(); i++) {
			if (n[i] - '0' > answer) {
				answer = n[i] - '0';
			}
		}

		return answer;
	}
};