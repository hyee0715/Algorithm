#include <iostream>
#include <algorithm>

#define MAX 10000
using namespace std;

int n;
long long m, arr[MAX], max_num = 0, answer = 0, sum = 0;

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		sum += arr[i];

		if (max_num < arr[i])
			max_num = arr[i];
	}

	cin >> m;
}

bool binary_search(long long target) {
	long long sum_num = 0;
	long long temp_arr[MAX];

	for (int i = 0; i < n; i++) {
		temp_arr[i] = arr[i];
	}

	for (int i = 0; i < n; i++) {
		if (temp_arr[i] > target) {
			temp_arr[i] = target;
		}

		sum_num += temp_arr[i];
	}

	if (sum_num <= m)
		return true;
	return false;
}

void solution() {
	sort(arr, arr + n);

	//모든 요청을 합한 값이 총 예산 m보다 작거나 같다면, 요청한 금액 중 가장 큰 값을 출력한 뒤 종료
	if (sum <= m) {
		cout << max_num;
		return;
	}

	//모든 요청을 합한 값이 총 예산 m보다 크다면, 배정할 예산의 상한액을 기준으로 이분탐색한다.
	long long left = 0;
	long long right = max_num;

	while (left <= right) {
		long long mid = (left + right) / 2;

		if (binary_search(mid)) { // 요청 예산들 중 mid보다 큰 값들은 모두 mid로 바꾸고, 합계가 m보다 작거나 같다면 true 리턴. 예산 상한액을 더 올려본다.
			left = mid + 1;
			answer = max(answer, mid);
		}
		else { // M보다 크다면, 예산 상한액을 낮춘다.
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