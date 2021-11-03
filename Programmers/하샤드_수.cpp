#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
	bool answer = true;
	int h = x;
	int num = 0;

	while (h >= 1) {
		num += h % 10;
		h = h / 10;
	}

	if (x % num == 0)
		answer = true;
	else
		answer = false;

	return answer;
}