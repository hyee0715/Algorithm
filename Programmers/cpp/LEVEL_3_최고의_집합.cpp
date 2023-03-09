#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
	vector<int> answer;

	if (s < n) {
		answer.push_back(-1);
		return answer;
	}

	if (s == n) {
		for (int i = 0; i < n; i++) {
			answer.push_back(1);
		}

		return answer;
	}

	int cnt = s / n;

	for (int i = 0; i < n; i++) {
		answer.push_back(cnt);
	}

	if (s % n != 0) {
		int plus = s % n;

		int idx = answer.size() - 1;

		while (plus > 0) {
			answer[idx]++;

			idx--;
			plus--;
		}
	}

	return answer;
}