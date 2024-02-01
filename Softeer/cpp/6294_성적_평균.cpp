#include <iostream>
#include <vector>

using namespace std;

int n, k; //학생 수, 구간 수

double getAvg(int sum, int num) {

	return (double)sum / num;
}

void settingCumulativeSum(vector<int>& score, vector<int>& cumul) {
	cumul[1] = score[1];

	for (int i = 2; i < score.size(); i++) {
		cumul[i] = cumul[i - 1] + score[i];
	}
}

int getSum(int start, int end, vector<int>& cumul) {
	if (start == 1) {
		return cumul[end];
	}

	return cumul[end] - cumul[start - 1];
}

void solution() {
	cin >> n >> k;

	vector<int> score(n + 1);

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		score[i] = a;
	}

	vector<int> cumul(score.size());

	settingCumulativeSum(score, cumul);

	for (int i = 0; i < k; i++) {
		int start, end;
		cin >> start >> end;

		int sum = getSum(start, end, cumul);

		double answer = getAvg(sum, end - start + 1);

		printf("%.2f\n", answer);
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);

	solution();

	return 0;
}