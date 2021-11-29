#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore();

	string str;
	vector<string> vec;
	stack<char> sta;

	for (int i = 0; i < n; i++) {
		getline(cin, str);
		vec.push_back(str);
		vec[i] += '\n';
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			if (vec[i][j] == ' ' || vec[i][j] == '\n') {
				while (!sta.empty()) {
					cout << sta.top();
					sta.pop();
				}
				cout << " ";
			}
			else {
				sta.push(vec[i][j]);
			}
		}
		cout << "\n";
	}
	return 0;
}