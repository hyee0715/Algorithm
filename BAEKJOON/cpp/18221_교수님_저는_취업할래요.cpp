#include <iostream>
#include <cstring>
#include <cmath>

#define MAX 1010
using namespace std;

int n;
int arr[MAX][MAX];

void input() {
	memset(arr, 0, sizeof(arr));

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

}

bool findStudentsInSqure(int sx, int sy, int ex, int ey) { // 왼쪽 위 점~오른쪽 아래 점 좌표를 파라미터로
	int cnt = 0;

	for (int i = sx; i <= ex; i++) {
		for (int j = sy; j <= ey; j++) {
			if (arr[i][j] == 1) {
				cnt++;
			}
		}
	}

	if (cnt >= 3) {
		return true;
	}
	else {
		return false;
	}
}

bool findStudentsInLine(int direction, int start, int end, int common) { // direction : 0이면 세로, 1이면 가로
	int cnt = 0;

	if (direction == 0) { // 세로
		for (int i = start; i <= end; i++) {
			if (arr[i][common] == 1) {
				cnt++;
			}
		}
	}
	else { // 가로
		for (int i = start; i <= end; i++) {
			if (arr[common][i] == 1) {
				cnt++;
			}
		}
	}

	if (cnt >= 3) {
		return true;
	}
	else {
		return false;
	}

}

void solution() {
	pair<int, int> sk, prof; // 성규와 교수님의 <x, y> 좌표

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 2) {
				sk = make_pair(i, j);
			}

			if (arr[i][j] == 5) {
				prof = make_pair(i, j);
			}
		}
	}


	// 성규와 교수님의 거리가 5 이상이 아니면 fail
	if (sqrt(pow((sk.first - prof.first), 2) + pow((sk.second - prof.second), 2)) < 5) {
		cout << "0";
		return;
	}

	if (sk.first == prof.first || sk.second == prof.second) {
		// 교수님과 성규가 같은 행 혹은 같은 열에 앉아있다면 둘을 잇는 선분 상에 성규가 아닌 학생이 세명 없으면 fail
		bool flag;
		
		if (sk.first == prof.first) {
			// x좌표가 같으므로 direction : 1 가로

			if (sk.second < prof.second) {
				flag = findStudentsInLine(1, sk.second, prof.second, sk.first);
			}
			else {
				flag = findStudentsInLine(1, prof.second, sk.second, sk.first);
			}
			
		}
		else if (sk.second == prof.second) {
			// y좌표가 같으므로 direction : 0 세로

			if (sk.first < prof.first) {
				flag = findStudentsInLine(0, sk.first, prof.first, sk.second);
			}
			else {
				flag = findStudentsInLine(0, prof.first, sk.first, sk.second);
			}
		}

		if (flag == false) {
			cout << "0";
			return;
		}
	}
	else {
		// 성규와 교수님을 꼭짓점으로 하는 축에 평행한 직사각형 안에 성규가 아닌 학생이 3명 이상 없으면 fail
		int sx, sy, ex, ey;

		if (sk.first < prof.first) {
			sx = sk.first;
			ex = prof.first;
		}
		else {
			sx = prof.first;
			ex = sk.first;
		}

		if (sk.second < prof.second) {
			sy = sk.second;
			ey = prof.second;
		}
		else {
			sy = prof.second;
			ey = sk.second;
		}

		if (!findStudentsInSqure(sx, sy, ex, ey)) { // false가 반환되면 학생 3명 이상이 없는 것이므로 fail
			cout << "0";
			return;
		}
	}

	cout << "1";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}