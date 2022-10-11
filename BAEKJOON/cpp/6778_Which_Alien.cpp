#include <iostream>
using namespace std;

int antenna, eyes;

void input() {
	cin >> antenna >> eyes;
}

void solution() {
	if (antenna >= 3 && eyes <= 4) {
		cout << "TroyMartian\n";
	}

	if (antenna <= 6 && eyes >= 2) {
		cout << "VladSaturnian\n";
	}

	if (antenna <= 2 && eyes <= 3) {
		cout << "GraemeMercurian\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}