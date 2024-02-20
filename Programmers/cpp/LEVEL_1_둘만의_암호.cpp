#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

string solution(string s, string skip, int index) {
	string answer = "";

	unordered_set<char> us;

	for (int i = 0; i < skip.length(); i++) {
		us.insert(skip[i]);
	}

	for (int i = 0; i < s.length(); i++) {
		char c = s[i];

		for (int j = 0; j < index; j++) {
			c = (char)(c + 1);

			if (c > 'z') {
				c = 'a';
			}

			if (us.find(c) != us.end()) {
				j--;
			}
		}

		answer += c;
	}

	return answer;
}