#include <iostream>
#include <string>
using namespace std;

string s;
int joi_cnt = 0, ioi_cnt = 0;

void input() {
	cin >> s;
}

void solution() {
	for (int i = 0; i < s.size() - 2; i++) {
		if (s[i + 0] == 'J' && s[i + 1] == 'O' && s[i + 2] == 'I') {
			joi_cnt++;
		}

		if (s[i + 0] == 'I' && s[i + 1] == 'O' && s[i + 2] == 'I') {
			ioi_cnt++;
		}
	}

	cout << joi_cnt << "\n" << ioi_cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}