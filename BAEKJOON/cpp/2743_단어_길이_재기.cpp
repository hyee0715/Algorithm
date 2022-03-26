#include <iostream>
#include <string>
using namespace std;

string s;

void input() {
	cin >> s;
}

void solution() {
	cout << s.size();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}