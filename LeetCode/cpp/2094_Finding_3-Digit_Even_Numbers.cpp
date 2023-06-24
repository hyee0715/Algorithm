class Solution {
public:
	void dfs(int cnt, vector<int>& digits, vector<bool>& visit, vector<int>& v, set<int>& st) {
		if (cnt == 3) {
			if (v[0] == 0 || v[2] % 2 != 0) {
				return;
			}

			int num = 0;
			for (int n : v) {
				num = num * 10 + n;
			}

			st.insert(num);
		}
		else {
			for (int i = 0; i < digits.size(); i++) {
				if (visit[i] == true) {
					continue;
				}
				visit[i] = true;
				v.push_back(digits[i]);
				dfs(cnt + 1, digits, visit, v, st);
				v.pop_back();
				visit[i] = false;
			}
		}
	}

	vector<int> findEvenNumbers(vector<int>& digits) {
		vector<int> answer;

		vector<bool> visit(digits.size(), false);
		vector<int> v;
		set<int> st;

		dfs(0, digits, visit, v, st);

		for (int n : st) {
			answer.push_back(n);
		}

		return answer;
	}
};