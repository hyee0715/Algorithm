#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string guitar[1000];

bool compare(string a, string b) {
	if (a.size() < b.size()) {
		return 1;
	}
	else if (a.size() > b.size()) {
		return 0;
	}
	else {
		int aSum = 0;
		int bSum = 0;

		for (int i = 0; i < a.size(); i++) {
			if (a[i] - '0' >= 0 && a[i] - '0' <= 9) {
				aSum += a[i] - '0';
			}

			if (b[i] - '0' >= 0 && b[i] - '0' <= 9) {
				bSum += b[i] - '0';
			}
		}

		if (aSum < bSum) {
			return 1;
		}
		else if (aSum > bSum) {
			return 0;
		}
		else {
			return a < b;
		}
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> guitar[i];
	}

	sort(guitar, guitar + n, compare);

	for (int i = 0; i < n; i++) {
		cout << guitar[i] << "\n";
	}

	return 0;
}