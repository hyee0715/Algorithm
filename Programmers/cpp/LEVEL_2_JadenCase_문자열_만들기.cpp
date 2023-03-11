#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
	string answer = "";

	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			continue;
		}

		if (i == 0 || s[i - 1] == ' ') {
			s[i] = toupper(s[i]);
			continue;
		}

		s[i] = tolower(s[i]);
	}

	answer = s;

	return answer;
}