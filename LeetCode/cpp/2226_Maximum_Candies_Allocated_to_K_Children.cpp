class Solution {
public:
	bool check(vector<int>& candies, long long k, int mid) {
		long long cnt = 0;
		for (int candy : candies) {
			if (mid == 0) {
				break;
			}

			cnt += (candy / mid);
		}

		if (cnt >= k) {
			return true;
		}

		return false;
	}

	int maximumCandies(vector<int>& candies, long long k) {
		int answer = 0;

		if (candies.size() == 1) {
			return candies[0] / k;
		}

		sort(candies.begin(), candies.end());

		int left = 0;
		int right = candies[candies.size() - 1];

		while (left <= right) {
			int mid = left + (right - left) / 2;

			if (check(candies, k, mid)) {
				answer = max(answer, mid);
				left = mid + 1;
			}
			else {
				right = mid - 1;
			}
		}

		if (answer == 0) {
			long long total = 0;

			for (int n : candies) {
				total += n;
			}

			if (total >= k) {
				answer = 1;
			}
		}

		return answer;
	}
};