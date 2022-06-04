#include <iostream>

#define MAX 500000
using namespace std;

int n, x, sum = 0, max_num, max_cnt;
int arr[MAX];

void input() {
	cin >> n >> x;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

void solution() {
	//첫째날 + x일 더해서 sum에 담는다.
	for (int i = 0; i < x; i++) {
		sum += arr[i];
	}

	max_num = sum;
	
	if (max_num == 0)
		max_cnt = 0;
	else
		max_cnt = 1;

	//둘째날부터 마지막까지 누적합 구한다.
	for (int i = 0; i < n; i++) {
		sum = sum - arr[i] + arr[i + x];

		if (sum > max_num) {
			max_num = sum;
			max_cnt = 1;
		}
		else if (sum == max_num && max_num != 0)
			max_cnt++;
	}

	if (max_cnt == 0) {
		cout << "SAD";
	}
	else
		cout << max_num << "\n" << max_cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}