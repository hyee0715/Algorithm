#include <iostream>
#include <string>
using namespace std;

string s1, s2;
int a = 0, b = 0;
pair<int, int> answer = {0, 0};

void input() {
	cin >> s1 >> s2;
}

string make_min(string s) {	//최솟값 만들기
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '6') {
			s[i] = '5';
		}
	}

	return s;
}

string make_max(string s) { //최댓값 만들기
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '5') {
			s[i] = '6';
		}
	}

	return s;
}

int make_num(string s) { //문자열을 숫자화 하기	
	int n;

	n = s[0] - '0';

	for (int i = 1; i < s.size(); i++) {
		n = (n * 10) + (s[i] - '0');
	}

	return n;
}

void solution() {
	//최솟값 구하기
	s1 = make_min(s1);
	s2 = make_min(s2);

	a = make_num(s1);
	b = make_num(s2);

	answer.first = a + b;

	//최댓값 구하기
	s1 = make_max(s1);
	s2 = make_max(s2);

	a = make_num(s1);
	b = make_num(s2);

	answer.second = a + b;

	cout << answer.first << " " << answer.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	input();
	solution();

	return 0;
}