class SparseVector {
    int[] num;

    SparseVector(int[] nums) {
        num = new int[nums.length];

        int idx = 0;
        for (int n : nums) {
            num[idx++] = n;
        }
    }

    // Return the dotProduct of two sparse vectors
    public int dotProduct(SparseVector vec) {
        int answer = 0;

        int[] list = vec.num;

        for (int i = 0; i < list.length; i++) {
            answer += (num[i] * list[i]);
        }

        return answer;
    }
}

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1 = new SparseVector(nums1);
// SparseVector v2 = new SparseVector(nums2);
// int ans = v1.dotProduct(v2);