#include <iostream>
#include <vector>
using namespace std;

int n, answer = 0;
vector<int> students, apples;

void input() {
	cin >> n;

	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		students.push_back(a);
		apples.push_back(b);
	}
}

void solution() {
	for (int i = 0; i < n; i++) {
		answer += (apples[i] % students[i]);
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