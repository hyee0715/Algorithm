class Solution {
public:
	int findKthPositive(vector<int>& arr, int k) {
		int cnt = 1;
		int answer = 0;

		for (int i = 0; i < arr.size(); i++) {
			if (cnt != arr[i]) {
				k--;
				i--;
			}

			if (k == 0) {
				break;
			}

			if (i != arr.size() - 1) {
				cnt++;
			}
		}

		while (k > 0) {
			cnt++;
			k--;
		}

		return cnt;
	}
};