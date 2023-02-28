class Solution {
public:
	bool nothingChanged(vector<vector<int>>& board, vector<vector<int>>& prevBoard) {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] != prevBoard[i][j]) {
					return false;
				}
			}
		}

		return true;
	}

	vector<vector<int>> candyCrush(vector<vector<int>>& board) {
		vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
		queue<vector<pair<int, int>>> blocksQueue;
		queue<pair<int, int>> zeroQueue;
		vector<vector<int>> prevBoard(board.size(), vector<int>(board[0].size()));

		while (1) {
			for (int i = 0; i < board.size(); i++) {
				for (int j = 0; j < board[i].size(); j++) {
					prevBoard[i][j] = board[i][j];
				}
			}

			//가로 탐색
			for (int i = 0; i < board.size(); i++) {
				vector<pair<int, int>> temp;

				for (int j = 0; j < board[i].size() - 1; j++) {
					if (board[i][j] == board[i][j + 1]) {
						if (temp.empty()) {
							temp.push_back({ i, j });
						}

						temp.push_back({ i, j + 1 });
					}
					else {
						if (!temp.empty() && temp.size() >= 3) {
							blocksQueue.push(temp);
						}

						temp.clear();
					}
				}

				if (!temp.empty() && temp.size() >= 3) {
					blocksQueue.push(temp);

					temp.clear();
				}
			}

			//세로 탐색
			for (int i = 0; i < board[0].size(); i++) {
				vector<pair<int, int>> temp;

				for (int j = 0; j < board.size() - 1; j++) {
					if (board[j][i] == board[j + 1][i]) {
						if (temp.empty()) {
							temp.push_back({ j, i });
						}

						temp.push_back({ j + 1, i });
					}
					else {
						if (!temp.empty() && temp.size() >= 3) {
							blocksQueue.push(temp);
						}

						temp.clear();
					}
				}

				if (!temp.empty() && temp.size() >= 3) {
					blocksQueue.push(temp);

					temp.clear();
				}
			}

			//사탕 비우기
			while (!blocksQueue.empty()) {
				vector<pair<int, int>> v = blocksQueue.front();
				blocksQueue.pop();

				for (int i = 0; i < v.size(); i++) {
					int x = v[i].first;
					int y = v[i].second;

					board[x][y] = 0;
				}
			}

			//사탕 아래로 떨어뜨리기
			for (int i = 0; i < board[0].size(); i++) {
				while (!zeroQueue.empty()) {
					zeroQueue.pop();
				}

				for (int j = board.size() - 1; j >= 0; j--) {
					if (board[j][i] == 0) {
						zeroQueue.push({ i, j });
					}

					if (board[j][i] != 0 && !zeroQueue.empty()) {
						int x = zeroQueue.front().second;
						int y = zeroQueue.front().first;
						zeroQueue.pop();

						board[x][y] = board[j][i];
						board[j][i] = 0;

						zeroQueue.push({ i, j });
					}
				}
			}

			if (nothingChanged(board, prevBoard)) {
				break;
			}
		}

		return board;
	}
};