class Solution {
public:
	vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
		vector<int> answer;

		for (int i = 0; i < arr1.size(); i++) {
			if (find(arr2.begin(), arr2.end(), arr1[i]) != arr2.end()) {
				if (find(arr3.begin(), arr3.end(), arr1[i]) != arr3.end()) {
					answer.push_back(arr1[i]);
				}
			}
		}

		return answer;
	}
};