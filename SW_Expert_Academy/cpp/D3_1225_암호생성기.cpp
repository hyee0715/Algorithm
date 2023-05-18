#include <iostream>
#include <queue>
using namespace std;

int tc;
queue<int> q;

void input() {
	cin >> tc;
	
	for (int i = 0; i < 8; i++) {
		int a;
		cin >> a;
		q.push(a);
	}
}

void solution() {
	int cnt = 1;

	while (1) {
		int n = q.front();
		q.pop();

		n -= cnt;

		if (n <= 0) {
			n = 0;
			q.push(n);

			break;
		}

		q.push(n);

		if (cnt == 5) {
			cnt = 1;
		}
		else {
			cnt++;
		}
	}

	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 10; i++) {
		input();

		cout << "#" << i << " ";
		solution();
		cout << "\n";
	}

	return 0;
}