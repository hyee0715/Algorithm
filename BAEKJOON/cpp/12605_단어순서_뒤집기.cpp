#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> v;
string s;

void initialize() {
	v.clear();
}

void input() {
	getline(cin, s);
}

void solution() {
	string temp;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			v.push_back(temp);
			temp.clear();
			continue;
		}
		
		if (s[i] != ' ') {
			temp += s[i];
		}
	}

	if (!temp.empty()) {
		v.push_back(temp);
		temp.clear();
	}

	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i];

		if (i != 0) {
			cout << " ";
		}
	}
	
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tc;
	cin >> tc;
	cin.ignore();

	for (int i = 0; i < tc; i++) {
		initialize();
		input();

		cout << "Case #" << i + 1 << ": ";

		solution();
	}

	return 0;
}