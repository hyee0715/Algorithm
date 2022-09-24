class Solution {
public:
	int maxNumberOfApples(vector<int>& weight) {
		int sum = 0;
		int answer = 0;

		sort(weight.begin(), weight.end());

		for (int i = 0; i < weight.size(); i++) {
			if ((sum + weight[i]) <= 5000) {
				answer++;
				sum += weight[i];
			}
		}

		return answer;
	}
};