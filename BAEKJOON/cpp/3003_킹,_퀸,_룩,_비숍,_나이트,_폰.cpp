#include <iostream>
#include <vector>
using namespace std;

vector<int> chess, answer;

void input() {
	int n;
	for (int i = 0; i < 6; i++) {
		cin >> n;
		chess.push_back(n);
	}
}

void solution() {
	vector<int> original = { 1, 1, 2, 2, 2, 8 };

	for (int i = 0; i < chess.size(); i++) {
		answer.push_back(original[i] - chess[i]);
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
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