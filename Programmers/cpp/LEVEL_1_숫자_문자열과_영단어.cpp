#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string s) {
	int answer = 0;
	string strAnswer;
	unordered_map<string, char> um;

	string numbers[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

	for (int i = 0; i < 10; i++) {
		um[numbers[i]] = (char)(i + '0');
	}

	string temp;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			if (!temp.empty()) {
				strAnswer += um[temp];
				temp.clear();
			}

			strAnswer += s[i];
			continue;
		}

		temp += s[i];

		if (um.count(temp)) {
			strAnswer += um[temp];
			temp.clear();
		}
	}

	if (!temp.empty()) {
		strAnswer += um[temp];
		temp.clear();
	}

	answer = stoi(strAnswer);

	return answer;
}