class Solution {
public:
	int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
		int arr[1001];
		int answer = 0;
		memset(arr, 0, sizeof(arr));

		for (int i = 0; i < startTime.size(); i++) {
			for (int j = startTime[i]; j <= endTime[i]; j++) {
				arr[j]++;
			}
		}

		answer = arr[queryTime];
		return answer;
	}
};