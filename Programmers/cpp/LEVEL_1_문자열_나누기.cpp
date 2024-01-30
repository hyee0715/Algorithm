#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 0;

	char init = s[0];
	int initCnt = 0;
	int cnt = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == init) {
			initCnt++;
		}
		else {
			cnt++;
		}

		if (initCnt == cnt) {
			answer++;
			initCnt = 0;
			cnt = 0;

			if (i < s.length() - 1) {
				init = s[i + 1];
			}
		}
	}

	if (initCnt > 0 || cnt > 0) {
		answer++;
	}

	return answer;
}