#include <iostream>
#include <algorithm>

#define MAX 50
using namespace std;

int n, answer = 0;
int a[MAX], b[MAX];

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
}

void solution() {
	sort(a, a + n);
	sort(b, b + n, greater<>());

	for (int i = 0; i < n; i++) {
		answer += (a[i] * b[i]);
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