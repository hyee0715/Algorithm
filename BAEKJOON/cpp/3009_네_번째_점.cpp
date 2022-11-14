#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> um1, um2;
int a, b, ans1, ans2;

void solution() {
	for (int i = 0; i < 3; i++) {
		cin >> a >> b;
		
		um1[a]++;
		um2[b]++;
	}

	for (pair<int, int> m : um1) {
		if (m.second != 2) {
			ans1 = m.first;
		}
	}

	for (pair<int, int> m : um2) {
		if (m.second != 2) {
			ans2 = m.first;
		}
	}
	
	cout << ans1 << " " << ans2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}