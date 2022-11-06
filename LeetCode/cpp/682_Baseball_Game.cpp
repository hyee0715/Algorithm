class Solution {
public:
	int calPoints(vector<string>& operations) {
		int answer = 0;
		vector<int> v;

		for (int i = 0; i < operations.size(); i++) {
			if (operations[i] == "C") {
				v.pop_back();
				continue;
			}

			if (operations[i] == "D") {
				int n = v.back();
				v.push_back(n * 2);
				continue;
			}

			if (operations[i] == "+") {
				int a = v[v.size() - 1];
				int b = v[v.size() - 2];

				v.push_back(a + b);
				continue;
			}

			int n = stoi(operations[i]);
			v.push_back(n);
		}

		for (int i = 0; i < v.size(); i++) {
			answer += v[i];
		}

		return answer;
	}
};