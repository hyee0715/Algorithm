class Solution {
public:
	vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
		vector<bool> answer;

		int maxNum = -1;

		for (int candy : candies) {
			maxNum = max(maxNum, candy);
		}

		for (int candy : candies) {
			if (candy + extraCandies >= maxNum) {
				answer.push_back(true);
			}
			else {
				answer.push_back(false);
			}
		}

		return answer;
	}
};