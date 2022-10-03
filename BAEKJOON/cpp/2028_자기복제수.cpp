#include <iostream>
#include <string>
using namespace std;

int n;

void input() {
	cin >> n;
}

void solution() {
	int square = n * n;
	string st_squre = to_string(square);
	string st_n = to_string(n);

	int idx = st_squre.size() - 1;

	for (int i = st_n.size() - 1; i >= 0; i--) {
		if (st_n[i] != st_squre[idx]) {
			cout << "NO\n";
			return;
		}
		
		idx--;
	}
	
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		input();
		solution();
	}

	return 0;
}