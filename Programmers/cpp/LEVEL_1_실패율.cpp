#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<int, double> failureRate;

bool compare(int x, int y) {
	double xRate = failureRate[x];
	double yRate = failureRate[y];

	if (xRate <= yRate) {
		if (xRate == yRate) {
			if (x < y) {
				return true;
			}

			return false;
		}

		return false;
	}

	return true;
}

double getFailureRate(int allPlayers, int notClearPlayers) {

	return (double)notClearPlayers / allPlayers;
}

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;

	unordered_map<int, int> allPlayersStage;
	unordered_map<int, int> notClearPlayersStage;

	for (int stage : stages) {
		notClearPlayersStage[stage]++;

		for (int i = 1; i <= stage; i++) {
			allPlayersStage[i]++;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (allPlayersStage.count(i) == 0) {
			allPlayersStage[i] = 0;
		}
	}

	for (auto m : allPlayersStage) {
		if (notClearPlayersStage.count(m.first) == 0) {
			failureRate[m.first] = (double)0;

			continue;
		}

		double rate = getFailureRate(allPlayersStage[m.first], notClearPlayersStage[m.first]);

		failureRate[m.first] = rate;
	}

	for (int i = 1; i <= N; i++) {
		answer.push_back(i);
	}

	sort(answer.begin(), answer.end(), compare);

	return answer;
}