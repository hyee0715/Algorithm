class Solution {
public:
	vector<string> invalidTransactions(vector<string>& transactions) {
		vector<string> name, city, answer;
		vector<int> time, amount;
		vector<bool> seen(transactions.size(), false);

		int cnt = 0;
		for (int i = 0; i < transactions.size(); i++) {
			string temp;

			for (int j = 0; j < transactions[i].length(); j++) {
				if (transactions[i][j] == ',') {
					if (cnt == 0) {
						name.push_back(temp);
						cnt++;
					}
					else if (cnt == 1) {
						time.push_back(stoi(temp));
						cnt++;
					}
					else {
						amount.push_back(stoi(temp));
						cnt = 0;
					}

					temp.clear();
					continue;
				}

				temp += transactions[i][j];
			}

			city.push_back(temp);
			temp.clear();
		}

		for (int i = 0; i < transactions.size(); i++) {
			if (amount[i] > 1000) {
				answer.push_back(transactions[i]);
				seen[i] = true;
			}
		}

		queue<int> q;

		for (int i = 0; i < transactions.size() - 1; i++) {
			for (int j = i + 1; j < transactions.size(); j++) {
				if (abs(time[i] - time[j]) <= 60) {
					if (name[i] == name[j] && city[i] != city[j]) {
						q.push(i);
						q.push(j);
					}
				}
			}
		}

		while (!q.empty()) {
			int n = q.front();
			q.pop();

			if (!seen[n]) {
				answer.push_back(transactions[n]);
				seen[n] = true;
			}
		}

		return answer;
	}
};