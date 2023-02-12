class Solution {
public:
	vector<int> countBits(int n) {
		vector<int> answer;

		for (int i = 0; i <= n; i++) {
			int cnt = 0;
			int num = i;

			while (num > 0) {
				num = num & (num - 1);
				cnt++;
			}

			answer.push_back(cnt);
		}

		return answer;
	}
};