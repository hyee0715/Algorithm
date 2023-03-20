class Solution {
public:
	int largestAltitude(vector<int>& gain) {
		int answer = 0;
		int sum = 0;

		for (int i = 0; i < gain.size(); i++) {
			sum += gain[i];
			answer = max(answer, sum);
		}

		return answer;
	}
};