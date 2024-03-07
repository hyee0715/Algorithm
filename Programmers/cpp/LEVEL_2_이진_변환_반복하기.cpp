#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int zeroCnt = 0;

string getBinary(string n) {
	string removeZero = "";

	for (int i = 0; i < n.length(); i++) {
		if (n[i] != '0') {
			removeZero += n[i];
		}
		else {
			zeroCnt++;
		}
	}

	int num = removeZero.length();

	string ret = "";
	while (num > 0) {
		ret += (char)((num % 2) + '0');
		num /= 2;
	}

	return ret;
}

vector<int> solution(string s) {
	vector<int> answer;

	int cnt = 0;
	while (s != "1") {
		s = getBinary(s);
		cnt++;
	}

	answer = { cnt, zeroCnt };
	return answer;
}