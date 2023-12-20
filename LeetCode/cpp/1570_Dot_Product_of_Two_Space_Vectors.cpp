class SparseVector {
public:
	vector<int> num;

	SparseVector(vector<int> &nums) {
		num.clear();

		for (int n : nums) {
			num.push_back(n);
		}
	}

	// Return the dotProduct of two sparse vectors
	int dotProduct(SparseVector& vec) {
		int answer = 0;

		vector<int> v = vec.num;

		for (int i = 0; i < v.size(); i++) {
			answer += (num[i] * v[i]);
		}

		return answer;
	}
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);