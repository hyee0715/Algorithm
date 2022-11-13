#include <iostream>
using namespace std;

char c;

void input() {
	cin >> c;
}

void solution() {
	if (c == 'N' || c == 'n')
		cout << "Naver D2";
	else
		cout << "Naver Whale";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}