#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
	string answer = "";
	answer += '0';

	char foodNum = (char)(food.size() - 1) + '0';

	for (int i = food.size() - 1; i >= 0; i--) {
		int count = food[i] / 2;

		for (int j = 0; j < count; j++) {
			answer = foodNum + answer + foodNum;
		}

		foodNum--;
	}

	return answer;
}