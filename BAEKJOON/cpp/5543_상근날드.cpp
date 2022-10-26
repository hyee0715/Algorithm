#include <iostream>
#include <vector>
using namespace std;

int answer = 4001;
vector<int> hamburger, drink;

void input() {
	int n;
	for (int i = 0; i < 3; i++) {
		cin >> n;
		hamburger.push_back(n);
	}

	for (int i = 0; i < 2; i++) {
		cin >> n;
		drink.push_back(n);
	}
}

void solution() {
	for (int i = 0; i < hamburger.size(); i++) {
		for (int j = 0; j < drink.size(); j++) {
			if (answer > hamburger[i] + drink[j] - 50) {
				answer = hamburger[i] + drink[j] - 50;
			}
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