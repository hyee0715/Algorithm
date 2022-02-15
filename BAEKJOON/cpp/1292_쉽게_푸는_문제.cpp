#include <iostream>
#include <vector>

#define MAX 1001
using namespace std;

int a, b;
vector<int> num;
int answer = 0;

void input() {
	cin >> a >> b;
}

void solution() {
	int cnt = 1;
	num.push_back(cnt);
	
	while (num.size() <= b) {
		for (int i = 1; i <= cnt; i++) {
			num.push_back(cnt);

		}
		cnt++;
	}

	for (int i = 1; i < num.size(); i++) {
		cout << num[i] << " ";
	}

	for (int i = a; i <= b; i++) {
		answer += num[i];
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