class Solution {
public:
	bool judgeCircle(string moves) {
		int rCnt = 0, lCnt = 0, uCnt = 0, dCnt = 0;

		for (int i = 0; i < moves.length(); i++) {
			if (moves[i] == 'U') {
				uCnt++;
			}
			else if (moves[i] == 'D') {
				dCnt++;
			}
			else if (moves[i] == 'R') {
				rCnt++;
			}
			else {
				lCnt++;
			}
		}

		if ((uCnt != dCnt) || (rCnt != lCnt)) {
			return false;
		}

		return true;
	}
};