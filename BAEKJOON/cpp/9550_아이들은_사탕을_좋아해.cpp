#include <iostream>
#include <vector>
using namespace std;

int n, k, answer = 0;
vector<int> candy;

void initialize() {
	answer = 0;
	candy.clear();
}

void input() {
	cin >> n >> k;

	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		candy.push_back(a);
	}
}

void solution() {
	for (int i = 0; i < candy.size(); i++) {
		answer += (candy[i] / k);
	}

	cout << answer << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		initialize();
		input();
		solution();
	}

	return 0;
}