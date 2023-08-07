#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> sequence) {
	long long answer = 0;

	if (sequence.size() == 1) {
		answer = max(sequence[0] * -1, sequence[0]);
		return answer;
	}

	vector<long long> v1, v2;

	for (int i = 0; i < sequence.size(); i++) {
		if (i % 2 != 0) {
			v1.push_back(sequence[i] * -1);
			v2.push_back(sequence[i]);
		}
		else {
			v1.push_back(sequence[i]);
			v2.push_back(sequence[i] * -1);
		}
	}

	long long dp1 = v1[0];
	long long max1 = -1;

	for (int i = 1; i < v1.size(); i++) {
		dp1 = max(dp1 + v1[i], v1[i]);

		max1 = max(max1, dp1);
	}

	long long dp2 = v2[0];
	long long max2 = -1;

	for (int i = 1; i < v2.size(); i++) {
		dp2 = max(dp2 + v2[i], v2[i]);

		max2 = max(max2, dp2);
	}

	answer = max(max1, max2);

	return answer;
}