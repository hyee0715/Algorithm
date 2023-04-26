#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer = { 0, 0 };
	set<string> dup;

	char startChar = words[0][0];

	int cnt = 0;
	int idx = 0;

	for (string word : words) {
		if (word[0] != startChar || dup.find(word) != dup.end()) {
			answer = { idx + 1, cnt + 1 };
			break;
		}

		dup.insert(word);
		startChar = word[word.length() - 1];

		idx++;

		if (idx == n) {
			idx = 0;
			cnt++;
		}
	}

	return answer;
}