#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
	vector<int> answer(2, -1);
	int minLen = 1000001;

	int left = 0, right = 0;
	int sum = sequence[left];

	if (sum == k) {
		answer[0] = left;
		answer[1] = right;
		minLen = right - left + 1;
	}

	while (left < sequence.size() && right < sequence.size()) {
		if (sum == k) {
			if (right - left + 1 < minLen) {
				minLen = right - left + 1;
				answer[0] = left;
				answer[1] = right;
			}

			right++;
			sum += sequence[right];
		}

		if (sum < k) {
			right++;
			sum += sequence[right];
		}

		if (sum > k) {
			sum -= sequence[left];
			left++;
		}
	}

	return answer;
}