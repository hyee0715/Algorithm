class Solution {
public:
	void dfs(unordered_map<int, vector<int>>& um, vector<bool>& visit, int prev, int cur, vector<pair<int, int>>& vec) {
		if (prev != -1) {
			if (prev < cur) {
				vec.push_back({ prev, cur });
			}
			else {
				vec.push_back({ cur, prev });
			}
		}

		visit[cur] = true;

		vector<int> v = um[cur];
		for (int i = 0; i < v.size(); i++) {
			if (visit[v[i]] == false) {
				dfs(um, visit, cur, v[i], vec);
			}
		}
	}

	int makeConnected(int n, vector<vector<int>>& connections) {
		unordered_map<int, vector<int>> um;
		vector<bool> visit(n, false);
		vector<pair<int, int>> vec;
		set<pair<int, int>> st;

		for (vector<int> con : connections) {
			um[con[0]].push_back(con[1]);
			um[con[1]].push_back(con[0]);
		}

		for (vector<int> con : connections) {
			st.insert({ con[0], con[1] });
		}

		int connectionCnt = 0;
		for (auto m : um) {
			if (visit[m.first] == false) {
				dfs(um, visit, -1, m.first, vec);
				connectionCnt++;
			}
		}

		for (pair<int, int> v : vec) {
			st.erase(v);
		}

		int notVisitCnt = n - um.size();
		if (st.size() < notVisitCnt + connectionCnt - 1) {
			return -1;
		}

		return notVisitCnt + connectionCnt - 1;
	}
};