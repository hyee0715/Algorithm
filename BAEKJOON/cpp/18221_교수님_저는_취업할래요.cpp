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

bool findStudentsInSqure(int sx, int sy, int ex, int ey) { // ���� �� ��~������ �Ʒ� �� ��ǥ�� �Ķ���ͷ�
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

bool findStudentsInLine(int direction, int start, int end, int common) { // direction : 0�̸� ����, 1�̸� ����
	int cnt = 0;

	if (direction == 0) { // ����
		for (int i = start; i <= end; i++) {
			if (arr[i][common] == 1) {
				cnt++;
			}
		}
	}
	else { // ����
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
	pair<int, int> sk, prof; // ���Կ� �������� <x, y> ��ǥ

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


	// ���Կ� �������� �Ÿ��� 5 �̻��� �ƴϸ� fail
	if (sqrt(pow((sk.first - prof.first), 2) + pow((sk.second - prof.second), 2)) < 5) {
		cout << "0";
		return;
	}

	if (sk.first == prof.first || sk.second == prof.second) {
		// �����԰� ���԰� ���� �� Ȥ�� ���� ���� �ɾ��ִٸ� ���� �մ� ���� �� ���԰� �ƴ� �л��� ���� ������ fail
		bool flag;
		
		if (sk.first == prof.first) {
			// x��ǥ�� �����Ƿ� direction : 1 ����

			if (sk.second < prof.second) {
				flag = findStudentsInLine(1, sk.second, prof.second, sk.first);
			}
			else {
				flag = findStudentsInLine(1, prof.second, sk.second, sk.first);
			}
			
		}
		else if (sk.second == prof.second) {
			// y��ǥ�� �����Ƿ� direction : 0 ����

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
		// ���Կ� �������� ���������� �ϴ� �࿡ ������ ���簢�� �ȿ� ���԰� �ƴ� �л��� 3�� �̻� ������ fail
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

		if (!findStudentsInSqure(sx, sy, ex, ey)) { // false�� ��ȯ�Ǹ� �л� 3�� �̻��� ���� ���̹Ƿ� fail
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