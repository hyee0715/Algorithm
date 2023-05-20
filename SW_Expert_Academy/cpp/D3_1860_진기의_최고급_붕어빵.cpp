#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k; //n : 사람 수, m : k개의 붕어빵을 만들기 위해 필요한 시간, k : 붕어빵 수
vector<int> nums; // 손님들이 도착하는 시간

void initialize() {
	nums.clear();
}

void input() {
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		nums.push_back(a);
	}
}

void solution() {
	sort(nums.begin(), nums.end());

	int endTime = nums[nums.size() - 1];

	int time = 0;
	int bread = 0;
	int idx = 0;

	for (int i = 0; i <= endTime; i++) { // 손님들이 들어올 가능성이 있는 모든 시간 반복
		if (time == m) {
			bread += k;
			time = 0;
		}

		if (nums[idx] == i) {
			if (bread == 0) {
				cout << "Impossible";
				return;
			}
			else {
				bread--;
				idx++;
			}
		}

		time++;
	}

	cout << "Possible";
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