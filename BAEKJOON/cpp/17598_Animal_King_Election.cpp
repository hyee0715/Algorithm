#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> animal;
int lion = 0, tiger = 0;

void input() {
	for (int i = 0; i < 9; i++) {
		string s;
		cin >> s;

		animal.push_back(s);
	}
}

void solution() {
	for (int i = 0; i < animal.size(); i++) {
		if (animal[i] == "Lion") {
			lion++;
			continue;
		}

		tiger++;
	}

	if (lion > tiger) {
		cout << "Lion";
		return;
	}

	cout << "Tiger";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}