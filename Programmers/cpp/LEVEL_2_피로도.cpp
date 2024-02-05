#include <string>
#include <vector>

using namespace std;

int maxNum = 0;

void findMaxNum(vector<int>& list, vector<vector<int>>& dungeons, int k) {
	int cnt = 0;
	int power = k;

	for (int idx : list) {
		int need = dungeons[idx][0];
		int minus = dungeons[idx][1];

		if (need > power) {
			break;
		}
		else {
			power -= minus;
			cnt++;
		}
	}

	maxNum = max(maxNum, cnt);
}

void dfs(int cnt, vector<int>& arr, vector<bool>& visit, vector<int>& list, vector<vector<int>>& dungeons, int k) {
	if (cnt == arr.size()) {
		findMaxNum(list, dungeons, k);

		return;
	}
	else {
		for (int i = 0; i < arr.size(); i++) {
			if (visit[i] == true) continue;
			visit[i] = true;
			list.push_back(arr[i]);
			dfs(cnt + 1, arr, visit, list, dungeons, k);
			list.pop_back();
			visit[i] = false;
		}
	}
}

int solution(int k, vector<vector<int>> dungeons) {
	int answer = 0;

	vector<int> arr(dungeons.size());

	for (int i = 0; i < arr.size(); i++) {
		arr[i] = i;
	}

	vector<bool> visit(arr.size(), false);
	vector<int> list;

	dfs(0, arr, visit, list, dungeons, k);

	answer = maxNum;
	return answer;
}