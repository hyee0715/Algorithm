class Solution {
public:
	unordered_map<int, vector<int>> makeMap(vector<vector<int>>& adjacentPairs) {
		unordered_map<int, vector<int>> um;

		for (vector<int> pairs : adjacentPairs) {
			int a = pairs[0];
			int b = pairs[1];

			um[a].push_back(b);
			um[b].push_back(a);
		}

		return um;
	}

	unordered_map<int, int> makeCntMap(vector<vector<int>>& adjacentPairs) {
		unordered_map<int, int> um;

		for (vector<int> pairs : adjacentPairs) {
			int a = pairs[0];
			int b = pairs[1];

			um[a]++;
			um[b]++;
		}

		return um;
	}

	set<int> initializeVisit(vector<vector<int>>& adjacentPairs) {
		set<int> visit;

		for (vector<int> pairs : adjacentPairs) {
			int a = pairs[0];
			int b = pairs[1];

			visit.insert(a);
			visit.insert(b);
		}

		return visit;
	}

	pair<int, int> findOneCountNumber(unordered_map<int, int>& cntMap) {
		pair<int, int> pair = { INT_MAX, INT_MAX };

		for (auto m : cntMap) {
			if (m.second == 1) {
				if (pair.first == INT_MAX) {
					pair = { m.first, INT_MAX };
				}
				else {
					pair = { pair.first, m.first };
				}
			}
		}

		return pair;
	}

	vector<int> bfs(int start, unordered_map<int, vector<int>>& um, unordered_map<int, int>& cntMap, set<int>& visit) {
		vector<int> answer;

		queue<int> q;
		q.push(start);
		visit.erase(start);

		while (!q.empty()) {
			int x = q.front();
			q.pop();

			answer.push_back(x);

			if (um.count(x) == 1) {
				vector<int> v = um[x];

				for (int i = 0; i < v.size(); i++) {
					if (cntMap[v[i]] == 2 && visit.find(v[i]) != visit.end()) {
						q.push(v[i]);
						visit.erase(v[i]);
					}
				}
			}
		}

		return answer;
	}

	vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
		vector<int> answer;

		unordered_map<int, vector<int>> um = makeMap(adjacentPairs);
		unordered_map<int, int> cntMap = makeCntMap(adjacentPairs);

		set<int> visit = initializeVisit(adjacentPairs);

		pair<int, int> oneCnt = findOneCountNumber(cntMap);

		answer = bfs(oneCnt.first, um, cntMap, visit);

		answer.push_back(oneCnt.second);

		return answer;
	}
};