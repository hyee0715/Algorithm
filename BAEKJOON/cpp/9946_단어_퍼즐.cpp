#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string original, matching;

void solution() {
	if (original.length() != matching.length()) {
		cout << "different\n";
		
		return;
	}

	unordered_map<char, int> map;

	for (char c : original) {
		map[c]++;
	}

	for (char c : matching) {
		map[c]--;
	}

	for (auto m : map) {
		if (m.second != 0) {
			cout << "different\n";

			return;
		}
	}

	cout << "same\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int cnt = 1;

	while (1) {
		cin >> original >> matching;

		if (original == "END" && matching == "END")
			break;

		cout << "Case " << cnt << ": ";

		cnt++;

		solution();
	}

	return 0;
}