#include <string>
#include <vector>

using namespace std;

bool isCapitalLetter(char c) {
	if (c >= 'A' && c <= 'Z') {
		return true;
	}

	return false;
}

string solution(string s, int n) {
	string answer = "";

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == ' ') {
			answer += s[i];
			continue;
		}

		int num = s[i] + n;
		int zNum = 'Z';
		int smallZNum = 'z';

		if (isCapitalLetter(s[i])) {
			if (num > zNum) {
				int cnt = num - zNum;

				answer += ('A' + cnt - 1);
			}
			else {
				answer += (char)(s[i] + n);
			}
		}
		else {
			if (num > smallZNum) {
				int cnt = num - smallZNum;

				answer += ('a' + cnt - 1);
			}
			else {
				answer += (char)(s[i] + n);
			}
		}
	}

	return answer;
}