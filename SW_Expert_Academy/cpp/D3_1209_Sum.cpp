#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<vector<int>> nums(100, vector<int>(100, 0));

void initialize() {
	nums.clear();
	nums.assign(100, vector<int>(100, 0));
}

void input() {
	cin >> n;

	int a;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			cin >> nums[i][j];
		}
	}
}

void solution() {
	int answer = 0;
	int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;

	for (int i = 0; i < 100; i++) {
		sum1 = 0;
		sum2 = 0;

		for (int j = 0; j < 100; j++) {
			sum1 += nums[i][j];
			sum2 += nums[j][i];
		}

		sum3 += nums[i][i];
		sum4 += nums[i][100 - i - 1];

		answer = max(answer, max(sum1, sum2));
	}
	
	answer = max(answer, max(sum3, sum4));

	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 10; i++) {
		initialize();
		input();

		cout << "#" << i << " ";
		solution();
		cout << "\n";
	}

	return 0;
}