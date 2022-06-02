#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
	int answer = 0;
	vector<int> vec;
	int phonekemon = nums.size() / 2;

	sort(nums.begin(), nums.end());
	vec.push_back(nums[0]);
	for (int i = 1; i < nums.size(); i++) {
		if (nums[i] != nums[i - 1]) {
			vec.push_back(nums[i]);
		}
	}

	if (vec.size() >= phonekemon) {
		answer = phonekemon;
	}
	else {
		answer = vec.size();
	}

	return answer;
}