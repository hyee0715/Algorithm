#include <iostream>
#include <string>
using namespace std;

string a, b;

void input() {
	cin >> a >> b;
}

void solution() {
	int answer = 0;

	for (int i = 0; i < a.length(); i++) {
		if (a[i] != b[i]) {
			answer++;
		}
	}

	cout << "Hamming distance is " << answer << ".\n";
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