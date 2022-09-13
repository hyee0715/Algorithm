class Solution {
public:
	int fixedPoint(vector<int>& arr) {
		int answer = -1;

		for (int i = 0; i < arr.size(); i++) {
			if (i == arr[i]) {
				answer = i;
				break;
			}
		}

		return answer;
	}
};