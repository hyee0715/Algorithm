#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cctype>
using namespace std;

string s, answer;
set<string> st;
vector<string> words;
string ignore[10] = { "i", "pa", "te", "ni", "niti", "a", "ali",  "nego", "no", "ili" };


void input() {
	getline(cin, s);
}

void solution() {
	string temp;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			words.push_back(temp);
			temp.clear();
			continue;
		}

		temp += s[i];
	}

	if (!temp.empty()) {
		words.push_back(temp);
		temp.clear();
	}

	for (int i = 0; i < 10; i++) {
		st.insert(ignore[i]);
	}

	for (int i = 0; i < words.size(); i++) {
		if ((i == 0 && st.find(words[i]) != st.end()) || (st.find(words[i]) == st.end())) {
			answer += toupper(words[i][0]);
		}
	}

	cout << answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}