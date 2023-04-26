#include <string>
#include <vector>

using namespace std;

void dfs(char ch[], int cnt, string word, string s, vector<string>& v) {
	if (cnt == 5) {
		return;
	}
	else {
		for (int i = 0; i < 5; i++) {
			s += ch[i];
			v.push_back(s);
			dfs(ch, cnt + 1, word, s, v);
			s.erase(s.begin() + s.length() - 1);
		}
	}
}

int solution(string word) {
	int answer = 0;

	char ch[] = { 'A', 'E', 'I', 'O', 'U' };

	string s;
	vector<string> v;
	dfs(ch, 0, word, s, v);

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == word) {
			answer = i + 1;
			break;
		}
	}

	return answer;
}