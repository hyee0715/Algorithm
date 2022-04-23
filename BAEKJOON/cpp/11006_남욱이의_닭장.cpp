#include <iostream>
using namespace std;

int n, m; // n : 모든 닭의 다리 수의 합, m : 닭의 수
int u, t; // u : 다리가 잘린 닭의 수, t : 멀쩡한 닭의 수
int original_leg_num; // 원래 있어야 할 다리 갯수

void input() {
	cin >> n >> m;
}

void solution() {
	u = 0, t = 0;

	original_leg_num = m * 2;

	u = original_leg_num - n;

	t = m - u;

	cout << u << " " << t << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++) {
		input();
		solution();
	}

	return 0;
}