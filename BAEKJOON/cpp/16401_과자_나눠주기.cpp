#include <iostream>
#include <algorithm>

#define MAX 1000001
using namespace std;

int m, n;
long long arr[MAX];
long long max_num = 0, answer;

void input() {
	cin >> m >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	
		if (max_num < arr[i]) {
			max_num = arr[i];
		}
	}
}

bool binary_search(long long target) {
	long long cnt = 0;

	for (int i = 1; i <= n; i++) {
		cnt += arr[i] / target;
	}

	if (cnt >= m)
		return true;
	return false;
}

void solution() {
	long long start = 1;
	long long end = max_num;

	while (start <= end) {
		long long mid = (start + end) / 2;

		if (binary_search(mid)) {
			start = mid + 1;
			answer = max(answer, mid);
		}
		else {
			end = mid - 1;
		}
	}

	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}