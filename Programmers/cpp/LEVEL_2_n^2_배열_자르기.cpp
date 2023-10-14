#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
	vector<int> answer(right - left + 1);

	int idx = 0;
	bool start = false;

	for (int i = left / n; i <= right / n; i++) {
		for (int j = 0; j < n; j++) {
			if (start == false) {
				start = true;
				j = (left % n);
			}

			if (idx == answer.size()) {
				break;
			}

			if (j <= i) {
				answer[idx++] = i + 1;
			}
			else {
				answer[idx++] = j + 1;
			}

		}
	}

	return answer;
}