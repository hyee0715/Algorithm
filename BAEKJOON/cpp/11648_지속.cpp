#include <iostream>
#include <string>
using namespace std;

string s;
int cnt = 0;

void input() {
	cin >> s;
}

void solution() {
	while (s.size() > 1) {
		int sum = 1;
		cnt++;

		for (int i = 0; i < s.size(); i++) {
			sum *= (s[i] - '0');
		}

		s = to_string(sum);
	}

	cout << cnt;
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