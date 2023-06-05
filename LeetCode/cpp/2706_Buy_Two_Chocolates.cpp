class Solution {
public:
	int buyChoco(vector<int>& prices, int money) {
		int answer = money;
		sort(prices.begin(), prices.end());

		if (prices[0] + prices[1] > money) {
			return answer;
		}

		answer -= prices[0];
		answer -= prices[1];

		return answer;
	}
};