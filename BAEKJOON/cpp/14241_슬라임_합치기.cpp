#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, answer = 0;
vector<int> slimes;

void input() {
	cin >> n;

	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		slimes.push_back(x);
	}
}

void solution() {
	sort(slimes.begin(), slimes.end());

	while (slimes.size() > 1) {
		int a = slimes.back();
		slimes.pop_back();

		int b = slimes.back();
		slimes.pop_back();

		answer += (a * b);
		slimes.push_back(a + b);
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