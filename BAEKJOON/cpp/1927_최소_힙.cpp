#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, x;
priority_queue<int, vector<int>, greater<int> > pq;
vector<int> answer;

void solution() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;

		if (x == 0) {
			if (pq.empty()) {
				answer.push_back(0);
			}
			else {
				answer.push_back(pq.top());
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}