#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> check(vector<string>& gems, int count, int target) {
	unordered_map<string, int> check_map;

	int left = 0, right = count - 1;

	for (int i = left; i <= right; i++) {
		check_map[gems[i]]++;
	}

	if (check_map.size() == target) {
		return { left + 1, right + 1 };
	}

	while (right < gems.size()) {
		if (check_map.size() == target) {
			return { left + 1, right + 1 };
		}

		check_map[gems[left]]--;

		if (check_map[gems[left]] == 0) {
			check_map.erase(gems[left]);
		}

		left++;
		right++;

		if (right == gems.size()) {
			break;
		}

		check_map[gems[right]]++;
	}

	if (check_map.size() == target) {
		return { left + 1, right + 1 };
	}

	return { -1, -1 };
}

vector<int> solution(vector<string> gems) {
	vector<int> answer(2, 0);
	unordered_map<string, int> mp;

	int min_num = 100001;

	for (string g : gems) {
		mp[g]++;
	}

	int count = mp.size(); //보석 종류 수

	int left = 1, right = gems.size();

	while (left <= right) {
		int mid = left + (right - left) / 2;

		vector<int> v = check(gems, mid, count);
		if (v[0] != -1 && v[1] != -1) {
			if (min_num > v[1] - v[0] + 1) {
				min_num = v[1] - v[0] + 1;
				answer = { v[0], v[1] };
			}

			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return answer;
}