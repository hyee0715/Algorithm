#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
	int answer = 0;
	unordered_map<int, int> um;

	for (int i = 0; i < nums.size(); i++) {
		um[nums[i]]++;
	}

	if (um.size() >= nums.size() / 2) {
		answer = nums.size() / 2;
	}
	else {
		answer = um.size();
	}

	return answer;
}