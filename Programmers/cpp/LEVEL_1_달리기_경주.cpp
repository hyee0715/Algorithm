#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void swap(int idx1, int idx2, vector<string>& players, unordered_map<string, int>& um) {
	string a = players[idx1];
	string b = players[idx2];

	players[idx2] = a;
	players[idx1] = b;

	um[a] = idx2;
	um[b] = idx1;
}

vector<string> solution(vector<string> players, vector<string> callings) {
	vector<string> answer;
	unordered_map<string, int> um;

	for (int i = 0; i < players.size(); i++) {
		um[players[i]] = i;
	}

	for (string name : callings) {
		int playerIdx = um[name];

		swap(playerIdx, playerIdx - 1, players, um);
	}

	answer = players;
	return answer;
}
