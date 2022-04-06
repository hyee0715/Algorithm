#include <iostream>
#include <string>
using namespace std;

int a;
string b;

void input() {
	cin >> a >> b;
}

void solution() {
	int n;

	for (int i = 2; i >= 0; i--) {
		n = b[i] - '0';

		cout << a * n << "\n";
	}
	
	
	n = stoi(b);
	cout << a * n;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}