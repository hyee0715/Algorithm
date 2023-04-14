class Solution {
public:
	string strWithout3a3b(int a, int b) {
		string answer;
		bool flag = false;

		if (a > b) {
			flag = true;
		}

		while (abs(a - b) + 1 < b && abs(a - b) + 1 < a) {
			if (flag) {
				answer += "aabb";
			}
			else {
				answer += "bbaa";
			}

			a -= 2;
			b -= 2;
		}

		if (a > b) {
			while (a >= 2 && b >= 1) {
				if (flag) {
					answer += "aab";
				}
				else {
					answer += "baa";
				}

				a -= 2;
				b -= 1;
			}
		}

		if (a < b) {
			while (a >= 1 && b >= 2) {
				if (flag) {
					answer += "abb";
				}
				else {
					answer += "bba";
				}

				a -= 1;
				b -= 2;
			}
		}

		if (flag) {
			while (a > 0) {
				answer += "a";
				a--;
			}

			while (b > 0) {
				answer += "b";
				b--;
			}
		}
		else {
			while (b > 0) {
				answer += "b";
				b--;
			}

			while (a > 0) {
				answer += "a";
				a--;
			}
		}

		return answer;
	}
};