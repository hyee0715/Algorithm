#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string x, y;

void input() {
	cin >> x >> y;
}

void solution() {
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());

	while (1) {
		if (x[0] == '0') {
			x.erase(0, 1);
		}
		else {
			break;
		}
	}

	while (1) {
		if (y[0] == '0') {
			y.erase(0, 1);
		}
		else {
			break;
		}
	}

	int nx = stoi(x);
	int ny = stoi(y);
	string answer = to_string(nx + ny);

	reverse(answer.begin(), answer.end());

	while (1) {
		if (answer[0] == '0') {
			answer.erase(0, 1);
		}
		else {
			break;
		}
	}

	cout << answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}