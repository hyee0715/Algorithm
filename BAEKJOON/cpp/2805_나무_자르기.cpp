#include <iostream>
#include <algorithm>

#define MAX 1000000
using namespace std;

int n;
long long m, arr[MAX], max_num = 0, answer = 0;

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		if (max_num < arr[i])
			max_num = arr[i];
	}
}

bool binary(long long target) {
	long long sum = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] >= target)
			sum += (arr[i] - target);
	}

	if (sum >= m)
		return true;
	return false;
}

// 절단기의 높이로 이분탐색한다. (자를 나무의 최대 높이)
void solution() {
	sort(arr, arr + n);

	long long left = 0;
	long long right = max_num;

	while (left <= right) {
		long long mid = (left + right) / 2;

		if (binary(mid)) { // 자른 나무의 합계가 m미터 이상이면 높이를 더 늘려보기(나무의 합계 줄이기)
			left = mid + 1;
			answer = max(answer, mid);
		}
		else { // 자른 나무의 합계가 m미터 미만이면 높이 줄이기(나무 합계 늘리기)
			right = mid - 1;
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