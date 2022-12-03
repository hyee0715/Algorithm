#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, score = 0;
string name;

void input() {
	cin >> n >> name;
}

void solution() {
	for (int i = 0; i < name.length(); i++) {
		score += (name[i] - 'A' + 1);
	}

	cout << score;
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