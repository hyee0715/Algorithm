#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define MAX 100000
using namespace std;

int n;
vector<pair<int, pair<int, string> > > member; // 나이순, 가입한 순, 이름

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int age;
		string name;
		cin >> age >> name;
		member.push_back(make_pair(age, make_pair(i, name)));
	}
}

void solution() {
	sort(member.begin(), member.end());

	for (int i = 0; i < member.size(); i++) {
		cout << member[i].first << " " << member[i].second.second << "\n";
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