#include <iostream>
using namespace std;

int minkook = 0, manse = 0;
int a, b, c, d;

void solution() {
	for (int i = 0; i < 2; i++) {
		cin >> a >> b >> c >> d;
	
		if (i == 0) {
			minkook = a + b + c + d;
		}
		else {
			manse = a + b + c + d;
		}
	}

	if (minkook >= manse) {
		cout << minkook;
	}
	else {
		cout << manse;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}