#include <string>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

void settingMap(vector<vector<int>>& board, unordered_map<int, stack<int>>& um) {
	for (int i = board.size() - 1; i >= 0; i--) {
		vector<int> b = board[i];

		for (int j = 0; j < b.size(); j++) {
			if (b[j] == 0) {
				continue;
			}

			um[j + 1].push(b[j]);
		}
	}
}

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	stack<int> basket;
	unordered_map<int, stack<int>> um;

	settingMap(board, um);

	for (int move : moves) {
		if (!um[move].empty()) {
			int doll = um[move].top();
			um[move].pop();

			if (!basket.empty()) {
				if (basket.top() == doll) {
					answer += 2;
					basket.pop();
				}
				else {
					basket.push(doll);
				}
			}
			else {
				basket.push(doll);
			}
		}
	}

	return answer;
}