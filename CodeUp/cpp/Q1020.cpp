#include <iostream>
#include <string>
using namespace std;

int main() {
	string num;
	getline(cin, num);

	string ret = "";

	for (int i = 0; i < 14; i++) {
		if (i != 6) {
			ret += num[i];
		}
	}

	cout << ret;

	return 0;
}