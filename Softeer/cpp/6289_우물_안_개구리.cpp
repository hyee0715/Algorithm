#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<int, int> weight; //회원번호, 무게
unordered_map<int, vector<int>> friends;  //회원번호, 친구목록
int n, m; //n:회원, m:친분관계
vector<int> person;
vector<pair<int, int>> link;

int answer = 0;

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		person.push_back(a);
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		link.push_back({ a, b });
	}
}

void init() {
	for (int i = 0; i < person.size(); i++) {
		weight[i + 1] = person[i];
	}

	for (int i = 0; i < link.size(); i++) {
		int a = link[i].first;
		int b = link[i].second;

		friends[a].push_back(b);
		friends[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (friends.count(i) == 0) {
			vector<int> v;

			friends[i].push_back(0);
			friends[i].clear();
		}
	}
}

void solution() {
	init();

	for (auto f : friends) {
		vector<int> v = f.second;

		if (v.size() == 0) {
			answer++;
			continue;
		}

		bool flag = false;
		int personNum = f.first;
		int personWeight = weight[personNum];

		for (int i = 0; i < v.size(); i++) {
			int friendNum = v[i];
			int friendWeight = weight[friendNum];

			if (personWeight <= friendWeight) {
				flag = true;
				break;
			}
		}

		if (!flag) {
			answer++;
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