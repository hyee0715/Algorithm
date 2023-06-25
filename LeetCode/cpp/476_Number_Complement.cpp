class Solution {
public:
	int findComplement(int num) {
		int answer = 0;
		string numBinary = "";

		while (num > 0) {
			if (num % 2 == 0) {
				numBinary += '0';
			}
			else {
				numBinary += '1';
			}
			num /= 2;
		}

		reverse(numBinary.begin(), numBinary.end());

		for (int i = 0; i < numBinary.length(); i++) {
			if (numBinary[i] == '0') {
				numBinary[i] = '1';
			}
			else {
				numBinary[i] = '0';
			}
		}

		int cnt = 0;
		for (int i = numBinary.length() - 1; i >= 0; i--) {
			answer += ((numBinary[i] - '0') * pow(2, cnt));
			cnt++;
		}

		return answer;
	}
};