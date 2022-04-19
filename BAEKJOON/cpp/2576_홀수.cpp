#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int sum = 0;
int arr[7];
vector<int> answer;

void input() {
	for (int i = 0; i < 7; i++) {
		cin >> arr[i];
	}
}


void solution() {
	for (int i = 0; i <7; i++) {
		if (arr[i] % 2 != 0) {
			answer.push_back(arr[i]);

			sum += arr[i];
		}
	}

	if (!answer.empty()) {
		sort(answer.begin(), answer.end());

		cout << sum << "\n" << answer[0];
	}
	else {
		cout << "-1";
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