#include <iostream>
using namespace std;

int n, k, answer = 0;
int arr[10];

void input() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void solution() {
	//k원을 만드는 데 필요한 동전 개수의 최솟값 구하기
	for (int i = n - 1; i >= 0; i--) {
		answer += k / arr[i];
		k = k % arr[i];
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