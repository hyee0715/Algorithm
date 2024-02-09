#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> rate = { 10, 20, 30, 40 };
vector<vector<int>> rateList;

bool compare(vector<int> x, vector<int> y) {
	if (x[0] >= y[0]) {
		if (x[0] == y[0]) {
			if (x[1] >= y[1]) {
				return true;;
			}
			return false;
		}
		return true;
	}
	return false;
}

void sortAnswer(vector<vector<int>>& answer) {
	sort(answer.begin(), answer.end(), compare);
}

vector<int> getDiscountedPrice(vector<int>& emoticons, vector<int>& rate) {
	vector<int> discountedPrice(rate.size(), 0);

	for (int i = 0; i < emoticons.size(); i++) {
		discountedPrice[i] = (int)(emoticons[i] * (double)(100 - rate[i]) / 100);
	}

	return discountedPrice;
}

void getDiscountRateDuplicatedCombination(int cnt, int limit, vector<int>& comb) {
	if (cnt == limit) {
		rateList.push_back(comb);

		return;
	}
	else {
		for (int i = 0; i < rate.size(); i++) {
			comb.push_back(rate[i]);
			getDiscountRateDuplicatedCombination(cnt + 1, limit, comb);
			comb.pop_back();
		}
	}
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
	vector<int> answer;
	vector<vector<int>> tempAnswer;

	vector<int> comb;
	getDiscountRateDuplicatedCombination(0, emoticons.size(), comb);

	for (vector<int> rate : rateList) {
		vector<int> discountedPrice = getDiscountedPrice(emoticons, rate);
		int totalPrice = 0;
		int totalMember = 0;

		for (vector<int> user : users) {
			int userRate = user[0];
			int userPrice = user[1];

			int priceSum = 0;
			for (int i = 0; i < rate.size(); i++) {
				if (rate[i] >= userRate) {
					priceSum += discountedPrice[i];
				}
			}

			if (priceSum >= userPrice) {
				totalMember++;
			}
			else {
				totalPrice += priceSum;
			}
		}

		tempAnswer.push_back({ totalMember, totalPrice });
	}

	sortAnswer(tempAnswer);

	answer = tempAnswer[0];
	return answer;
}