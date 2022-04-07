#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string s;
int alphabet[26];
char answer;

void input() {
	cin >> s;
}

bool find_max() { //가장 많이 사용된 알파벳이 여러개일 경우 false 반환
	int temp_max = -1;
	int temp_idx;

	for (int i = 0; i < 26; i++) {
		if (alphabet[i] > temp_max) {
			temp_max = alphabet[i];
			temp_idx = i;
			answer = i + 'a';
		}
	}

	for (int i = 0; i < 26; i++) {
		if (temp_idx != i) {
			if (alphabet[i] == temp_max) {
				return false;
			}
		}
	}

	return true;
}

void solution() {
	memset(alphabet, 0, sizeof(alphabet));
	
	for (int i = 0; i < s.size(); i++) {
		s[i] = tolower(s[i]);
	
		alphabet[s[i] - 'a']++;
	}

	//최댓값 찾기
	if (!find_max()) {
		cout << "?";
	}
	else {
		answer = toupper(answer);
		cout << answer;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}