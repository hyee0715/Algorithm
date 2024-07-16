#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

int count;
vector<bool> visit;
vector<char> members, v;
unordered_map<char, int> idxMap; //문자, 인덱스 번호

void settingIdxMap() {
	idxMap.clear();

	for (int i = 0; i < v.size(); i++) {
		idxMap[v[i]] = i;
	}
}

bool validateData(string data) {
	char left = data[0];
	char right = data[2];

	char op = data[3];

	int num = data[4] - '0';

	int leftIdx = idxMap[left];
	int rightIdx = idxMap[right];

	int sp = abs(leftIdx - rightIdx) - 1;

	if (op == '=') {
		if (sp != num) {
			return false;
		}
	}
	else if (op == '<') {
		if (!(sp < num)) {
			return false;
		}
	}
	else {
		if (!(sp > num)) {
			return false;
		}
	}

	return true;
}

bool validate(vector<string>& data) {
	for (string d : data) {
		if (!validateData(d)) {
			return false;
		}
	}

	return true;
}

void dfs(int cnt, vector<string>& data) {
	if (cnt == members.size()) {
		settingIdxMap();

		if (validate(data)) {
			count++;
		}

		return;
	}

	for (int i = 0; i < members.size(); i++) {
		if (visit[i] == true) {
			continue;
		}

		visit[i] = true;
		v.push_back(members[i]);
		dfs(cnt + 1, data);
		visit[i] = false;
		v.pop_back();
	}
}

int solution(int n, vector<string> data) {
	int answer = 0;
	count = 0;

	members = { 'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T' };

	visit.assign(members.size(), false);
	v.assign(0, 0);
	idxMap.clear();

	dfs(0, data);

	answer = count;

	return answer;
}