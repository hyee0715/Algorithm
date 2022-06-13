#include <iostream>

#define MAX 10
using namespace std;

int j[MAX], g[MAX];
int j_score = 0, g_score = 0;
int flag = 0;

void input() {
	for (int i = 1; i <= 9; i++) {
		cin >> j[i];
	}

	for (int i = 1; i <= 9; i++) {
		cin >> g[i];
	}
}

void solution() {
	for (int i = 1; i <= 9; i++) {
		j_score += j[i];

		if (j_score > g_score) {
			flag = 1;
		}

		g_score += g[i];

		if (flag == 1 && j_score < g_score)
			flag = 2;
	}

	if (flag == 2)
		cout << "Yes";
	else
		cout << "No";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}