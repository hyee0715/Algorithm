#include <iostream>
#include <algorithm>

#define MAX 1000000000
using namespace std;

long long x, y, z, answer = 1e11;

void input() {
	cin >> x >> y;
}

bool binary_search(long long target) {
	long long temp_z = ((y + target) * 100) / (x + target);

	if (temp_z != z)
		return true;
	return false;
}

void solution() {
	// 원래 승률 z 구하기. 99 또는 100이면 승률을 더이상 높이지 못하므로 -1 출력 후 종료.
	z = (y * 100) / x;

	if (z == 99 || z == 100) {
		cout << "-1";
		return;
	}

	// 앞으로 할 게임의 이긴 게임의 수로 이분탐색한다. (앞으로의 모든 게임에서 지지 않는다.)
	long long left = 1;
	long long right = MAX;

	while (left <= right) {
		long long mid = (left + right) / 2;

		if (binary_search(mid)) { // 원래 승률 z와 새로 구한 승률 temp_z가 다르면 앞으로 할 게임의 수를 낮춰본다.
			right = mid - 1;
			answer = min(answer, mid);
		}
		else { // 원래 승률 z와 새로 구한 승률 temp_z가 다르면 앞으로 할 게임의 수를 높인다.
			left = mid + 1;
		}
	}

	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}