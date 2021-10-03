#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	int qFront;

	while (q.size() > 1) {
		q.pop();
		qFront = q.front();
		q.pop();
		q.push(qFront);
	}

	cout << q.front();

	return 0;
}