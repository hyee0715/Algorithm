#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
	int answer = 0;
	long long pNum = stol(p);

	int left = 0, right = p.length() - 1;

	string s;
	for (int i = left; i <= right; i++) {
		s += t[i];
	}

	while (right < t.length()) {
		long long num = stol(s);

		if (num <= pNum) {
			answer++;
		}

		left++;
		right++;

		if (right == t.length()) {
			break;
		}

		s.erase(0, 1);
		s += t[right];
	}

	return answer;
}