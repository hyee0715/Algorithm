#include <string>
#include <vector>

using namespace std;

int solution(int num) {
	int answer = 0;

	long long number = (long long)num;

	int cnt = 0;
	while (number != 1) {
		if (cnt > 500) {
			break;
		}

		if (number % 2 == 0) {
			number = number / 2;
		}
		else {
			number = number * 3;
			number = number + 1;
		}

		cnt++;
	}

	if (number == 1) {
		answer = cnt;
	}
	else {
		answer = -1;
	}

	return answer;
}