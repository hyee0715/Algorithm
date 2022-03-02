#include <iostream>
#include <string>
#include <queue>
#include <vector>

#define MAX 10000
using namespace std;

queue<int> q;
vector<string> command;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;

		command.push_back(s);

		if (s == "push") {
			string a;
			cin >> a;
			command.push_back(a);
		}
	}

	for (int i = 0; i < command.size(); i++) {

		if (command[i] == "push") {
			int a = stoi(command[i + 1]);
			
			q.push(a);
		}

		if (command[i] == "pop") {
			if (!q.empty()) {
				cout << q.front() << "\n";
				q.pop();
			}
			else {
				cout << "-1" << "\n";
			}
		}

		if (command[i] == "size") {
			cout << q.size() << "\n";
		}

		if (command[i] == "empty") {
			if (q.empty())
				cout << "1" << "\n";
			else
				cout << "0" << "\n";
		}

		if (command[i] == "front") {
			if (!q.empty()) {
				cout << q.front() << "\n";
			}
			else {
				cout << "-1" << "\n";
			}
		}

		if (command[i] == "back") {
			if (!q.empty()) {
				cout << q.back() << "\n";
			}
			else {
				cout << "-1" << "\n";
			}
		}
	}

	return 0;
}