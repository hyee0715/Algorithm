class Solution {
public:
	int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
		int answer = arrivalTime + delayedTime;

		if (answer >= 24) {
			answer -= 24;
		}

		return answer;
	}
};