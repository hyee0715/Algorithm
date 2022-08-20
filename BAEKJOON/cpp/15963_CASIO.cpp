#include <iostream>
using namespace std;

long long n, m;
	
void input() {
	cin >> n >> m;
}

void solution() {
	if (n == m)
		cout << 1;
	else
		cout << 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();
	
	return 0;
}