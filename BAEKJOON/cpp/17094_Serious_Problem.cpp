#include <iostream>
#include <string>
using namespace std;

int n;
string s;

void input() {
	cin >> n >> s;
}

void solution() {
	int cnt_e = 0;
	int cnt_2 = 0;

	for (int i = 0; i < n; i++) {
		if (s[i] == '2')
			cnt_2++;
		else
			cnt_e++;
	}

	if (cnt_2 > cnt_e)
		cout << "2";
	else if (cnt_2 < cnt_e)
		cout << "e";
	else
		cout << "yee";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}