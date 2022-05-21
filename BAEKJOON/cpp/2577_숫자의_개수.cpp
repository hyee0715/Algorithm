#include <iostream>
#include <string>
#include <cstring>

#define MAX 10
using namespace std;

int a, b, c;
int num[MAX];
long long result;
string s;

void input() {
	cin >> a >> b >> c;
}

void solution() {
	memset(num, 0, sizeof(num));

	result = a * b * c;

	s = to_string(result);

	for (int i = 0; i < s.size(); i++) {
		num[s[i] - '0']++;
	}

	for (int i = 0; i < MAX; i++) {
		cout << num[i] << "\n";
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