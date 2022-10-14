#include <iostream>
#include <vector>
using namespace std;

vector<int> v, even;

void input() {
	v.clear();

	int n;
	for (int i = 0; i < 7; i++) {
		cin >> n;
		v.push_back(n);
	}
}

void solution() {
	int min = 101;
	int sum = 0;

	for (int i = 0; i < v.size(); i++) {
		if (v[i] % 2 == 0) {
			if (min > v[i]) {
				min = v[i];
			}

			sum += v[i];
		}
	}

	cout << sum << " " << min << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		input();
		solution();
	}

	return 0;
}