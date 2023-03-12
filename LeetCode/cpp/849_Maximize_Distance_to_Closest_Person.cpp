class Solution {
public:
	int maxDistToClosest(vector<int>& seats) {
		priority_queue<int> hi;
		int answer = 0;
		int zeroCnt = 0;

		int idx = 0, revIdx = seats.size() - 1;

		if (seats[0] == 0) {
			while (seats[idx] == 0) {
				zeroCnt++;
				idx++;
			}

			hi.push(zeroCnt);
			zeroCnt = 0;
		}

		if (seats[revIdx] == 0) {
			while (seats[revIdx] == 0) {
				zeroCnt++;
				revIdx--;
			}

			hi.push(zeroCnt);
			zeroCnt = 0;
		}

		for (int i = idx; i < revIdx; i++) {
			if (seats[i] == seats[i + 1] && seats[i] == 0) {
				if (zeroCnt == 0) {
					zeroCnt++;
				}

				zeroCnt++;
			}
			else {
				if (zeroCnt <= 2) {
					hi.push(1);
					zeroCnt = 0;
					continue;
				}

				if (zeroCnt % 2 == 0) {
					hi.push(zeroCnt / 2);
				}
				else {
					hi.push(zeroCnt / 2 + 1);
				}

				zeroCnt = 0;
			}
		}

		if (zeroCnt != 0) {
			if (zeroCnt % 2 == 0) {
				hi.push(zeroCnt / 2);
			}
			else {
				hi.push(zeroCnt / 2 + 1);
			}
		}

		answer = hi.top();

		return answer;
	}
};