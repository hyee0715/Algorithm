#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

vector<string> colComb;
unordered_set<string> uset;

bool validateChar(string a, string b) {
	for (int i = 0; i < a.length(); i++) {
		string s = "";
		if (b.find(s + a[i]) == string::npos) {
			return false;
		}
	}

	return true;
}

int findMinimalityCount() {
	vector<bool> isInvalid(colComb.size());

	for (int i = 0; i < colComb.size() - 1; i++) {
		for (int j = i + 1; j < colComb.size(); j++) {
			if (i == j || isInvalid[i] == true || isInvalid[j] == true) {
				continue;
			}

			string a = colComb[i];
			string b = colComb[j];

			if (a.length() < b.length()) {
				if (validateChar(a, b)) {
					isInvalid[j] = true;
				}
			}

			if (a.length() > b.length()) {
				if (validateChar(b, a)) {
					isInvalid[i] = true;
				}
			}
		}
	}

	int cnt = 0;
	for (bool flag : isInvalid) {
		if (!flag) {
			cnt++;
		}
	}

	return cnt;
}

string getStringFormatCombination(vector<int>& list, vector<string>& relation) {
	string s = "";

	for (int idx : list) {
		s += relation[idx];
	}

	return s;
}

vector<string> makeStr(vector<int>& list, vector<vector<string>>& relation) {
	vector<string> ret;

	for (vector<string> rel : relation) {
		string comb = getStringFormatCombination(list, rel);

		ret.push_back(comb);
	}

	return ret;
}

void getCombination(int idx, int cnt, int limit, vector<int>& list, vector<bool>& visit, vector<int>& indexes, vector<vector<string>>& relation, vector<string>& columns) {
	if (cnt == limit) {
		uset.clear();

		vector<string> combinations = makeStr(list, relation);

		for (string combination : combinations) {
			uset.insert(combination);
		}

		if (uset.size() == relation.size()) {
			string s = "";

			for (int n : list) {
				s += columns[n];
			}

			colComb.push_back(s);
		}

		return;
	}
	else {
		for (int i = idx; i < indexes.size(); i++) {
			if (visit[i] == true) continue;
			visit[i] = true;
			list.push_back(indexes[i]);
			getCombination(i, cnt + 1, limit, list, visit, indexes, relation, columns);
			visit[i] = false;
			list.pop_back();
		}
	}
}

int solution(vector<vector<string>> relation) {
	int answer = 0;

	vector<string> columns(relation[0].size());

	char alphabet = 'a';
	for (int i = 0; i < relation[0].size(); i++) {
		string s = "";
		columns[i] = s + (char)(alphabet + i);
	}

	vector<int> indexes(relation[0].size());

	for (int i = 0; i < relation[0].size(); i++) {
		indexes[i] = i;
	}

	vector<int> list;
	vector<bool> visit(indexes.size());

	for (int i = 1; i <= relation[0].size(); i++) {
		getCombination(0, 0, i, list, visit, indexes, relation, columns);
	}

	answer = findMinimalityCount();

	return answer;
}