class Solution {
public:
	string findWinner(vector<vector<char>>& board) {
		for (int i = 0; i < board.size(); i++) {
			if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == 'X') || (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == 'X')) {
				return "A";
			}
		}

		if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == 'X') || (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == 'X')) {
			return "A";
		}

		for (int i = 0; i < board.size(); i++) {
			if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == 'O') || (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == 'O')) {
				return "B";
			}
		}

		if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == 'O') || (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == 'O')) {
			return "B";
		}

		return "C";
	}

	bool isDraw(vector<vector<char>>& board) {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] == 'Z') {
					return false;
				}
			}
		}

		return true;
	}

	string tictactoe(vector<vector<int>>& moves) {
		string answer;
		vector<vector<char>> board(3, vector<char>(3, 'Z'));

		for (int i = 0; i < moves.size(); i++) {
			if (i % 2 == 0) {
				board[moves[i][0]][moves[i][1]] = 'X';
			}
			else {
				board[moves[i][0]][moves[i][1]] = 'O';
			}
		}

		answer = findWinner(board);

		if (answer == "A" || answer == "B") {
			return answer;
		}

		if (isDraw(board)) {
			return "Draw";
		}

		return "Pending";
	}
};