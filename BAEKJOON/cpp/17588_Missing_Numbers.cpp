#include <iostream>
#include <vector>
using namespace std;

int n, max_num = -1;
vector<bool> nums(201, false);
bool flag = false;

void solution() {
	cin >> n;

	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;

		nums[a] = true;

		if (max_num <= a) {
			max_num = a;
		}
	}

	for (int i = 1; i <= max_num; i++) {
		if (nums[i] == false) {
			cout << i << "\n";
			flag = true;
		}
	}

	if (!flag)
		cout << "good job";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	solution();

	return 0;
}