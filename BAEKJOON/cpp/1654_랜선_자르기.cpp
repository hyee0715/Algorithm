#include <iostream>
#include <algorithm>

#define MAX 10000
using namespace std;

int k, n;
long long arr[MAX], max_num = 0, answer = 0;

void input() {
	cin >> k >> n;

	for (int i = 0; i < k; i++) {
		cin >> arr[i];

		if (max_num < arr[i])
			max_num = arr[i];
	}
}

bool binary_search(long long target) {
	long long sum = 0;

	for (int i = 0; i <= k; i++) {
		sum += (arr[i] / target);
	}

	if (sum >= n)
		return true;
	return false;
}

// 만들(잘라낼) 랜선의 길이로 이분탐색
void solution() {
	sort(arr, arr + k);

	long long left = 0;
	long long right = max_num;

	while (left <= right) {
		long long mid = (left + right) / 2;

		if (binary_search(mid)) { // 갖고있는 랜선을 각각 mid의 길이만큼 잘라낸 개수가 n개 이상이면, mid의 길이를 더 늘려볼 수 있다.
			left = mid + 1;
			answer = max(answer, mid);
		}
		else { // 갖고있는 랜선을 각각 mid의 길이만큼 잘라낸 랜선의 개수가 n개 미만이면, mid의 길이를 줄인다.
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