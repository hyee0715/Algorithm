#include <iostream>
#include <vector>
using namespace std;

int n, answer = 0;
vector<int> v;

void input() {
	cin >> n;

	int a;
	for (int i = 0; i < 5; i++) {
		cin >> a;
		v.push_back(a);
	}
}

void solution() {
	for (int i = 0; i < 5; i++) {
		if (v[i] == n) {
			answer++;
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