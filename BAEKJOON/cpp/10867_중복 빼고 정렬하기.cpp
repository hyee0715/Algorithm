#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 100000
using namespace std;

int n;
vector<int> arr;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int input;
		cin >> input;

		arr.push_back(input);
	}
}

void solution() {
	sort(arr.begin(), arr.end());

	cout << arr[0] << " ";
	for (int i = 1; i < n; i++) {
		if (arr[i] != arr[i - 1]) {
			cout << arr[i] << " ";
		}
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