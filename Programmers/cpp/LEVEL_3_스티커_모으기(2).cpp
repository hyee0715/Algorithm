#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sticker) {
	int answer = 0;

	if (sticker.size() == 1) {
		return sticker[0];
	}

	vector<int> dp1(sticker.size());
	vector<int> dp2(sticker.size());


	//첫번째 스티커 떼는 경우 (맨 마지막 sticker 원소는 체크하지 않음)
	dp1[0] = sticker[0];
	dp1[1] = dp1[0];

	for (int i = 2; i < sticker.size() - 1; i++) {
		dp1[i] = max(dp1[i - 2] + sticker[i], dp1[i - 1]);
	}

	//첫번째 스티커 떼지 않는 경우
	dp2[0] = 0;
	dp2[1] = dp2[0] + sticker[1];

	for (int i = 2; i < sticker.size(); i++) {
		dp2[i] = max(dp2[i - 2] + sticker[i], dp2[i - 1]);
	}

	answer = max(dp1[dp1.size() - 2], dp2[dp2.size() - 1]);

	return answer;
}