class Solution {
public:
	int subtractProductAndSum(int n) {
		int answer = 0;

		string s = to_string(n);

		int product = 1;
		int sum = 0;

		for (int i = 0; i < s.length(); i++) {
			product *= (s[i] - '0');
			sum += (s[i] - '0');
		}

		answer = product - sum;
		return answer;
	}
};