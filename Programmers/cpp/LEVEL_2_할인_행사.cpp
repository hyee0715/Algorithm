#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool check(unordered_map<string, int> wantMap, unordered_map<string, int> discountMap) {
	for (pair<string, int> wm : wantMap) {
		if (discountMap[wm.first] < wm.second) {
			return false;
		}
	}

	return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
	int answer = 0;

	unordered_map<string, int> wantMap, discountMap;

	for (int i = 0; i < want.size(); i++) {
		wantMap[want[i]] = number[i];
	}

	for (int i = 0; i < 10; i++) {
		discountMap[discount[i]]++;
	}

	if (check(wantMap, discountMap)) {
		answer++;
	}

	int left = 0, right = 9;

	while (right < discount.size() - 1) {
		discountMap[discount[left]]--;
		left++;
		right++;
		discountMap[discount[right]]++;

		if (check(wantMap, discountMap)) {
			answer++;
		}
	}

	return answer;
}