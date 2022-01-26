#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> num;

void input() {
	for (int i = 0; i < 3; i++) {
		int input;
		cin >> input;
		num.push_back(input);
	}
}

void solution() {
	sort(num.begin(), num.end());

	for (int i = 0; i < 3; i++) {
		cout << num[i] << " ";
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