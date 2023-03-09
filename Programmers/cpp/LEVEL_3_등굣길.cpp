#include <string>
#include <vector>

using namespace std;

int check(vector<vector<int>>& board, vector<vector<int>>& memo, int curN, int curM) {
	if (curN >= board.size() || curM >= board[0].size()) {
		return 0;
	}

	if (board[curN][curM] == -1) {
		return 0;
	}

	if (curN == board.size() - 1 && curM == board[0].size() - 1) {
		return 1;
	}

	if (memo[curN][curM] != -1) {
		return memo[curN][curM];
	}

	return memo[curN][curM] = (check(board, memo, curN + 1, curM) % 1000000007 + check(board, memo, curN, curM + 1) % 1000000007) % 1000000007;
}

int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;

	vector<vector<int>> memo(n, vector<int>(m, -1));
	vector<vector<int>> board(n, vector<int>(m, 0));

	for (int i = 0; i < puddles.size(); i++) {
		int x = puddles[i][1];
		int y = puddles[i][0];

		board[x - 1][y - 1] = -1;
	}

	answer = check(board, memo, 0, 0);

	return answer;
}