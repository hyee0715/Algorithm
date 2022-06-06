#include <iostream>
#include <cstring>

#define MAX 100001
using namespace std;

int n, m;
int arr[MAX], sum[MAX];

void input() {
	cin >> n >> m;

	memset(sum, 0, sizeof(sum));

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];

		if (i == 1)
			sum[i] = arr[i];
		else
			sum[i] = sum[i - 1] + arr[i];
	}
}

void solution() {
	int a, b;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		cout << sum[b] - sum[a - 1] << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}