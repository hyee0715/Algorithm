#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	vector<int> sum;
	sum.push_back(0);

	for (int i = 1; i <= n; i++) {
		sum.push_back(sum[i - 1] + i);
	}

	int left = 0, right = 0;
	while (left < sum.size() && right < sum.size()) {
		if (sum[right] - sum[left] == n) {
			answer++;
			right++;
			continue;
		}

		if (sum[right] - sum[left] < n) {
			right++;
			continue;
		}

		left++;
	}

	return answer;
}