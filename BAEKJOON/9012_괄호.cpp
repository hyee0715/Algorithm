#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore();

	string str;
	vector<string> vec;
	stack<int> sta;
	bool isNo = false;

	for (int i = 0; i < n; i++) {
		getline(cin, str);
		vec.push_back(str);
	}

	for (int i = 0; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			if (vec[i][j] == '(') {
				sta.push(1);
			}
			else if (vec[i][j] == ')') {
				if (!sta.empty())
					sta.pop();
				else {
					isNo = true;
					break;
				}
			}
		}

		if (sta.empty() && !isNo) {
			cout << "YES";
		}
		else if (!sta.empty() || isNo) {
			cout << "NO";
			
			while (!sta.empty()) {
				sta.pop();
			}
		}

		cout << "\n";
		isNo = false;
	}

	return 0;
}