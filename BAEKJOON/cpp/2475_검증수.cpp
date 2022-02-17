#include <iostream>
#include <vector>

using namespace std;

vector<int> vec;
int answer;

void input() {
	int n;

	for (int i = 0; i < 5; i++) {
		cin >> n;
		vec.push_back(n);
	}
}

void solution() {
	int sum = 0;

	for (int i = 0; i < 5; i++) {
		sum += (vec[i] * vec[i]);
	}

	answer = sum % 10;
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