#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
	vector<int> answer;

	for (int i = 1; i <= (yellow / 2) + 1; i++) {
		if (yellow % i == 0) {
			int col = yellow / i;
			int row = i;

			if ((row * 2) + (col * 2) == brown - 4) {
				answer.push_back(col + 2);
				answer.push_back(row + 2);

				break;
			}
		}
	}

	return answer;
}