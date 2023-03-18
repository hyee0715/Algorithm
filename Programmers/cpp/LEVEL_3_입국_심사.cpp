#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long validate(long long num, vector<int> times) {
	long long cnt = 0;
	for (int i = 0; i < times.size(); i++) {
		cnt += num / times[i];
	}

	return cnt;
}

long long solution(int n, vector<int> times) {
	long long answer = 0;
	long long left = 0, right = 0;

	for (int i = 0; i < times.size(); i++) {
		right = max(right, (long long)times[i]);
	}

	right *= n;
	answer = right;

	while (left <= right) {
		long long mid = left + (right - left) / 2;

		if (validate(mid, times) >= n) {
			answer = min(answer, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return answer;
}