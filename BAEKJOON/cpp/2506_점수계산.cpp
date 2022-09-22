#include <iostream>
#include <vector>
using namespace std;

int n, answer = 0;
vector<int> v;

void input() {
	cin >> n;

	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
}

void solution() {
	bool prev = false;
	int cnt = 1;

	for (int i = 0; i < n; i++) {
		if (v[i] == 1) {
			if (prev) {
				cnt++;
			}

			prev = true;
			answer += cnt;

		}
		else {
			cnt = 1;
			prev = false;
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