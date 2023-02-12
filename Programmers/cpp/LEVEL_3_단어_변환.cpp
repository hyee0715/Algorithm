#include <string>
#include <vector>
#include <queue>

using namespace std;

bool check(string a, string b) {
	int diff = 0;

	for (int i = 0; i < a.length(); i++) {
		if (a[i] != b[i]) {
			diff++;
		}
	}

	if (diff == 1) {
		return true;
	}
	return false;
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	vector<bool> visit(words.size(), false);

	queue<pair<string, int>> q;
	q.push({ begin, 0 });

	while (!q.empty()) {
		string word = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (word == target) {
			answer = cnt;
			break;
		}

		for (int i = 0; i < words.size(); i++) {
			if (visit[i] == false && check(word, words[i])) {
				visit[i] = true;
				q.push({ words[i], cnt + 1 });
			}
		}
	}

	return answer;
}