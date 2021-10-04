#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

int main() {
	string str;
	getline(cin, str);

	queue<char> q;
	stack<char> sta;
	bool isQPush = false;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '<') {

			if (sta.empty()) {
				q.push(str[i]);
				isQPush = true;
			}
			else { // !sta.empty()
				while (!sta.empty()) {
					cout << sta.top();
					sta.pop();
				}

				q.push(str[i]);
				isQPush = true;
			}

		}
		else if (str[i] == '>') {
			q.push(str[i]);

			while (!q.empty()) {
				cout << q.front();
				q.pop();
				
			}

			isQPush = false;
		}
		else if (str[i] == ' ' && !isQPush) {
			while (!sta.empty()) {
				cout << sta.top();
				sta.pop();
			}

			cout << " ";
		}
		else if (isQPush) {
			q.push(str[i]);
		}
		else { // isQPush == false
			sta.push(str[i]);
		}
	}

	if (!sta.empty()) {
		while (!sta.empty()) {
			cout << sta.top();
			sta.pop();
		}
	}

	return 0;
}