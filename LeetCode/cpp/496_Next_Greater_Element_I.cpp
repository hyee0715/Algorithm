class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		vector<int> answer(nums1.size(), -1);
		stack<int> st;
		bool flag = false;

		for (int i = 0; i < nums1.size(); i++) {
			while (!st.empty()) {
				st.pop();
			}

			flag = false;

			for (int j = 0; j < nums2.size(); j++) {
				if (nums1[i] > nums2[j]) {
					st.push(nums2[j]);
					continue;
				}

				if (nums1[i] == nums2[j]) {
					flag = true;
					st.push(nums2[j]);
					continue;
				}

				if (flag == true) {
					answer[i] = nums2[j];
					break;
				}
				else {
					st.push(nums2[j]);
				}
			}
		}

		return answer;
	}
};