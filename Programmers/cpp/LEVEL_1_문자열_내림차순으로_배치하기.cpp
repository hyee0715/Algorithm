#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
	string answer = "";

	string a = "", b = "";

	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			b += s[i];
		}
		else {
			a += s[i];
		}
	}

	sort(a.begin(), a.end(), greater<>());
	sort(b.begin(), b.end(), greater<>());

	answer = a + b;

	return answer;
}