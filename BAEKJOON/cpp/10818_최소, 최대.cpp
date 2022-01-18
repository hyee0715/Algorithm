#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 1000000
using namespace std;

int n;
vector<int> answer;

void input() {
	cin >> n;

	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		answer.push_back(input);
	}
}

void solution() {
	sort(answer.begin(), answer.end());

	cout << answer[0] << " " << answer[answer.size() - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}