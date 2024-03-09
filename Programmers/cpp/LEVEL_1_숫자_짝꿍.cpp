#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string solution(string X, string Y) {
	string answer = "";

	unordered_map<int, int> mp1, mp2; //숫자, 횟수
	vector<int> v;

	for (int i = 0; i < X.length(); i++) {
		mp1[X[i] - '0']++;
	}

	for (int i = 0; i < Y.length(); i++) {
		mp2[Y[i] - '0']++;
	}

	for (auto m : mp1) {
		int num = m.first;
		int cnt = -1;

		if (mp2.count(num) != 0) {
			cnt = min(m.second, mp2[num]);
		}

		for (int i = 0; i < cnt; i++) {
			v.push_back(num);
		}
	}

	if (v.empty()) {
		answer = "-1";
		return answer;
	}

	sort(v.begin(), v.end(), greater<>());

	if (v.size() > 1 && v[0] == 0) {
		answer = "0";
		return answer;
	}

	for (int n : v) {
		answer += to_string(n);
	}

	return answer;
}