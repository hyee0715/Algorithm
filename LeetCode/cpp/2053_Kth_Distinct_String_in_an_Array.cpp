class Solution {
public:
	string kthDistinct(vector<string>& arr, int k) {
		string answer;
		unordered_map<string, int> um;
		int cnt = 0;

		for (int i = 0; i < arr.size(); i++) {
			um[arr[i]]++;
		}

		for (int i = 0; i < arr.size(); i++) {
			if (um[arr[i]] == 1) {
				cnt++;
			}

			if (cnt == k) {
				answer = arr[i];
				break;
			}
		}

		return answer;
	}
};