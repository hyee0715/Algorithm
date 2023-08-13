class Solution {
public:
	int maxCoins(vector<int>& piles) {
		int answer = 0;

		sort(piles.begin(), piles.end(), greater<>());

		int left = 1, right = piles.size() - 1;

		while (left < right) {
			answer += piles[left];

			left += 2;
			right--;
		}

		return answer;
	}
};