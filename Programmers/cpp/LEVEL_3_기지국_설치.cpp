#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;

	int count = 0;
	int width = 1 + w * 2;
	int cur = 1;

	for (int station : stations) {
		int covered = station - w;
		int aptNum = covered - 1;
		int notCoveredDistance = aptNum - cur + 1;

		count += (notCoveredDistance / width);

		if (notCoveredDistance % width > 0) {
			count++;
		}

		cur = station + w + 1;
	}

	if (cur > stations[stations.size() - 1]) {
		int notCoveredDistance = n - cur + 1;

		count += (notCoveredDistance / width);

		if (notCoveredDistance % width > 0) {
			count++;
		}
	}

	answer = count;

	return answer;
}