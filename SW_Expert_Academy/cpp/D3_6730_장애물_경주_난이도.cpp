#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;  //블록 개수
vector<int> blocks;

void initialize() {
	blocks.clear();
}

void input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		blocks.push_back(a);
	}
}

void solution() {
	int up = 0, down = 0;

	for (int i = 0; i < blocks.size() - 1; i++) {
		if (blocks[i] < blocks[i + 1]) {
			up = max(up, blocks[i + 1] - blocks[i]);
		}
		else {
			down = max(down, blocks[i] - blocks[i + 1]);
		}
	}

	cout << up << " " << down;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 1; i <= tc; i++) {
		initialize();
		input();

		cout << "#" << i << " ";

		solution();

		cout << "\n";
	}

	return 0;
}