#include <iostream>
#include <vector>
#include <string>
using namespace std;

int a, b;
vector<string> answer;

void input() {
	cin >> a >> b;
}

void solution() {
	if (a > b)
		answer.push_back("YES");
	else
		answer.push_back("NO");
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		input();

		if (a == 0 && b == 0) {
			break;
		}

		solution();
	}
	
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}

	return 0;
}