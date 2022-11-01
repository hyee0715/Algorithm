class Solution {
public:
	void duplicateZeros(vector<int>& arr) {
		vector<int> v;

		for (int i = 0; i < arr.size(); i++) {
			if (v.size() == arr.size())
				break;

			if (arr[i] != 0) {
				v.push_back(arr[i]);
			}
			else {
				for (int j = 0; j < 2; j++) {
					v.push_back(0);

					if (v.size() == arr.size())
						break;
				}
			}
		}

		for (int i = 0; i < v.size(); i++) {
			arr[i] = v[i];
		}
	}
};