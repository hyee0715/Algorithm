class Solution {
public:
	string generateTheString(int n) {
		if (n == 1) {
			return "a";
		}

		string answer = "";

		if (n % 2 == 0) {
			for (int i = 0; i < n - 1; i++) {
				answer += 'a';
			}

			answer += 'b';
		}
		else {
			for (int i = 0; i < n - 2; i++) {
				answer += 'a';
			}

			answer += 'b';
			answer += 'c';
		}

		return answer;
	}
};