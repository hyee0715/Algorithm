#include <iostream>
#include <cstring>
using namespace std;

bool pc[101];
int n, cnt = 0;

void solution() {
	memset(pc, false, sizeof(pc));

	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		if (pc[a] == true)
			cnt++;
		else
			pc[a] = true;
	}

	cout << cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}