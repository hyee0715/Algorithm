#include <iostream>
using namespace std;

int A, B, C;

void input() {
	cin >> A >> B >> C;
}

void solution() {
	cout << (A + B) % C << "\n" << ((A % C) + (B % C)) % C << "\n" << (A * B) % C << "\n" << ((A % C) * (B % C)) % C;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}