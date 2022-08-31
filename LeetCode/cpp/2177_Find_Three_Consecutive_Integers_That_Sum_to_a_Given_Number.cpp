class Solution {
public:
	vector<long long> sumOfThree(long long num) {
		vector<long long> answer;

		if ((num - 3) % 3 == 0) {
			long long n = (num - 3) / 3;

			answer.push_back(n);
			answer.push_back(n + 1);
			answer.push_back(n + 2);
		}

		return answer;
	}
};