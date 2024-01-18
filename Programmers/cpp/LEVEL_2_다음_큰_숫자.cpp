#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string getBinary(int n) {
	string s = "";

	while (n > 0) {
		s += ((n % 2) + '0');
		n = n / 2;
	}

	reverse(s.begin(), s.end());

	return s;
}

bool isSameOneCount(string orgNum, string nextNum) {
	int orgNumCnt = 0;
	int nextNumCnt = 0;

	for (int i = 0; i < orgNum.length(); i++) {
		if (orgNum[i] == '1') {
			orgNumCnt++;
		}
	}

	for (int i = 0; i < nextNum.length(); i++) {
		if (nextNum[i] == '1') {
			nextNumCnt++;
		}
	}

	if (orgNumCnt == nextNumCnt) {
		return true;
	}

	return false;
}

int solution(int n) {
	int answer = 0;

	string s = getBinary(n);

	int num = n + 1;
	while (1) {
		string nextNum = getBinary(num);

		if (isSameOneCount(s, nextNum)) {
			answer = num;
			break;
		}

		num++;
	}

	return answer;
}