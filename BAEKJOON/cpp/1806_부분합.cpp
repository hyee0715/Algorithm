#include <iostream>
#include <algorithm>

#define MAX 100000
#define INF 0x7FFFFFF
using namespace std;

int n, s, answer = INF;
int arr[MAX];

void input() {
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void solution() {
	int start = 0;
	int end = 0;
	int sum = arr[0];
	int cnt = 1;

	while (start <= end && end <= n) {
		if (sum >= s) {
			answer = min(answer, cnt);

			sum -= arr[start++];
			cnt--;
		}
		else {
			sum += arr[++end];
			cnt++;
		}
	}

	if (answer == INF)
		cout << 0;
	else
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