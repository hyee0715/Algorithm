#include <iostream>
#include <vector>
#include <string>
using namespace std;

string a, b;
int n;
pair<int, int> score;

void solution() {
	cin >> n;

	score = { 0, 0 };

	char c, d;
	for (int i = 0; i < n; i++) {
		cin >> c >> d;

		if (c == d) {
			score.first++;
		}
		else {
			score.second++;
		}
	}

	cout << a << " " << score.first << " " << b << " " << score.second << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> a >> b;

		if (a == "#" && b == "#") break;

		solution();
	}
	
	return 0;
}