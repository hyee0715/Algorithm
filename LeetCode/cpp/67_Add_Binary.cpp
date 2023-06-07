class Solution {
public:
	string additionalCal(string a, string b, string result, bool carry) {
		for (int i = a.length() - b.length() - 1; i >= 0; i--) {
			if (a[i] == '1') {
				if (carry) {
					result = '0' + result;
					continue;
				}

				result = '1' + result;
				continue;
			}

			if (carry) {
				carry = false;
				result = '1' + result;
				continue;
			}

			result = '0' + result;
		}

		if (carry) {
			result = '1' + result;
		}

		return result;
	}

	string addBinary(string a, string b) {
		string answer = "";

		int minLength = 0;

		if (a.length() < b.length()) {
			minLength = a.length();
		}
		else {
			minLength = b.length();
		}

		bool carry = false;
		for (int i = 1; i <= minLength; i++) {
			if (a[a.length() - i] == b[b.length() - i]) {
				if (a[a.length() - i] == '1') {
					if (carry) {
						// 둘 다 1인데 캐리가 있는 경우
						answer = '1' + answer;
						continue;
					}

					// 둘 다 1인데 캐리가 없는 경우
					carry = true;
					answer = '0' + answer;
					continue;
				}

				// 둘 다 0인데 캐리가 있는 경우
				if (carry) {
					carry = false;
					answer = '1' + answer;
					continue;
				}

				// 둘 다 0인데 캐리가 없는 경우
				answer = '0' + answer;
				continue;
			}

			// 둘이 같지 않을 때 캐리가 있는 경우
			if (carry) {
				answer = '0' + answer;
				continue;
			}

			// 둘이 같지 않을 때 캐리가 없는 경우
			answer = '1' + answer;
		}

		if (a.length() > b.length()) {
			answer = additionalCal(a, b, answer, carry);
		}
		else if (a.length() < b.length()) {
			answer = additionalCal(b, a, answer, carry);
		}
		else { // a와 b의 길이가 같은 경우
			if (carry) {
				answer = '1' + answer;
			}
		}

		return answer;
	}
};