#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int idx = -1;

static bool compare(string a, string b) {
	if (a[idx] < b[idx]) {
		return true;
	}

	if (a[idx] == b[idx]) {
		if (a < b) {
			return true;
		}

		return false;
	}

	return false;
}

vector<string> solution(vector<string> strings, int n) {
	vector<string> answer;

	idx = n;

	sort(strings.begin(), strings.end(), compare);

	for (string s : strings) {
		answer.push_back(s);
	}

	return answer;
}