#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
	int answer = 1;

	int startSection = section[0];
	int endSection = startSection + m - 1;

	for (int i = 0; i < section.size(); i++) {
		if (section[i] > endSection) {
			answer++;

			startSection = section[i];
			endSection = startSection + m - 1;
		}
	}

	return answer;
}