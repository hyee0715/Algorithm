#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s, t;

void input() {
	cin >> s >> t;
}

void solution() {
	// 반대로 t에서 s로 만들어본다.

	while (s.size() < t.size()) {
		if (t[t.size() - 1] == 'A') { // 문자열의 맨 뒤 값이 A이면 A를 제거한다.
			t.erase(t.size() - 1, 1);
		}
		else { // 문자열의 맨 뒤 값이 B이면 제거하고 뒤집는다.
			t.erase(t.size() - 1, 1);
			reverse(t.begin(), t.end());
		}
	}

	if (s == t) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}