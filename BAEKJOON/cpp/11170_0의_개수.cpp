#include <iostream>
#include <string>
using namespace std;

int a, b;

void input() {
	cin >> a >> b;
}

void solution() {
	int answer = 0;

	for (int i = a; i <= b; i++) {
		string s = to_string(i);

		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '0') {
				answer++;
			}
		}
	}

	cout << answer << "\n";
}

int main()
{
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