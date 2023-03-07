class Solution {
public:
	long long dividePlayers(vector<int>& skill) {
		long long answer = 0;
		long long totalSum = 0;

		sort(skill.begin(), skill.end());

		for (int n : skill) {
			totalSum += n;
		}

		long long subsetSum = totalSum / (skill.size() / 2);

		int left = 0, right = skill.size() - 1;

		while (left < right) {
			if (skill[left] + skill[right] != subsetSum) {
				return -1;
			}

			answer += (skill[left] * skill[right]);

			left++;
			right--;
		}

		return answer;
	}
};