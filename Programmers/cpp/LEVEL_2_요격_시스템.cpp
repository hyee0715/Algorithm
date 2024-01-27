#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
	if (a[1] <= b[1]) {
		if (a[1] == b[1]) {
			if (a[0] <= b[0]) {
				return true;
			}

			return false;
		}

		return true;
	}

	return false;
}

int solution(vector<vector<int>> targets) {
	int answer = 0;

	sort(targets.begin(), targets.end(), compare);

	vector<int> cur = { targets[0][0], targets[0][1] };

	for (int i = 0; i < targets.size(); i++) {
		if (targets[i][0] < cur[1]) {
			cur[0] = max(cur[0], targets[i][0]);
			cur[1] = min(cur[1], targets[i][1]);
		}
		else {
			answer++;
			cur = { targets[i][0], targets[i][1] };
		}
	}

	answer++;

	return answer;
}