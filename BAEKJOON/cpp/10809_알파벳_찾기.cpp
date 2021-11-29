#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	string s;
	getline(cin, s);

	vector<int> vec(26, -1);

	for (int i = 0; i < s.size(); i++) {
		if (vec[s[i] - 97] == -1)
			vec[s[i] - 97] = i;
	}

	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}

	return 0;
}