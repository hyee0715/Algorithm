#include <iostream>
#include <cmath>
using namespace std;

pair<pair<int, int>, int> a, b, c;

void input() {
	cin >> a.first.first >> a.first.second >> a.second 
		>> c.first.first >> c.first.second >> c.second;
}

void solution() {
	b.first.first = abs(a.second - c.first.first);
	b.first.second = (double)c.first.second / a.first.second;
	b.second = abs(a.first.first - c.second);

	cout << b.first.first << " " << b.first.second << " " << b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}