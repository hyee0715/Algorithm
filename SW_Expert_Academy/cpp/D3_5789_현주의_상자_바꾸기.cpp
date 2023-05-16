#include <iostream>
#include <vector>
using namespace std;

int n, q;
int tcNum = 1;

void solution() {
	cin >> n >> q;

	vector<int> boxes(n + 1, 0);
	
	int l, r;

	for (int i = 1; i <= q; i++) {
		cin >> l >> r;

		for (int j = l; j <= r; j++) {
			boxes[j] = i;
		}
	}

	cout << "#" << tcNum << " ";

	for (int i = 1; i < boxes.size(); i++) {
		cout << boxes[i] << " ";
	}
	cout << "\n";

	tcNum++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 1; i <= tc; i++) {
		solution();
	}

	return 0;
}