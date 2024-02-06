#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
	string answer = "Yes";

	int cards1Idx = 0;
	int cards2Idx = 0;
	int goalIdx = 0;

	while (true) {
		if (cards1Idx == cards1.size() || cards2Idx == cards2.size() || goalIdx == goal.size()) {
			break;
		}

		if (cards1[cards1Idx] == goal[goalIdx]) {
			cards1Idx++;
			goalIdx++;

			continue;
		}

		if (cards2[cards2Idx] == goal[goalIdx]) {
			cards2Idx++;
			goalIdx++;
		}
	}

	while (cards1Idx < cards1.size()) {
		if (goalIdx == goal.size()) {
			break;
		}

		if (cards1[cards1Idx] == goal[goalIdx]) {
			cards1Idx++;
			goalIdx++;
		}
		else {
			break;
		}
	}

	while (cards2Idx < cards2.size()) {
		if (goalIdx == goal.size()) {
			break;
		}

		if (cards2[cards2Idx] == goal[goalIdx]) {
			cards2Idx++;
			goalIdx++;
		}
		else {
			break;
		}
	}

	if (goalIdx != goal.size()) {
		answer = "No";
	}

	return answer;
}