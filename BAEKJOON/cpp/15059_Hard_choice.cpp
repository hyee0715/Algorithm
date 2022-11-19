#include <iostream>
#include <vector>
using namespace std;

vector<int> food, passenger;

void input() {
	int n;
	
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> n;

			if (i == 0) {
				food.push_back(n);
				continue;
			}

			if (i == 1) {
				passenger.push_back(n);
			}
		}
	}
}

void solution() {
	int answer = 0;

	for (int i = 0; i < 3; i++) {
		if (food[i] > passenger[i]) {
			continue;
		}

		answer += (passenger[i] - food[i]);
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