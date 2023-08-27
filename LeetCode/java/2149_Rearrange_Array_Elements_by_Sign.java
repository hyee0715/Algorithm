class Solution {
    public int[] rearrangeArray(int[] nums) {
        int answer[] = new int[nums.length];
        int[] n1 = new int[nums.length / 2];
        int[] n2 = new int[nums.length / 2];

        int idx1 = 0, idx2 = 0;
        for (int n : nums) {
            if (n < 0) {
                n2[idx2++] = n;
            } else {
                n1[idx1++] = n;
            }
        }

        int idx = 0;
        for (int i = 0; i < n1.length; i++) {
            answer[idx++] = n1[i];
            answer[idx++] = n2[i];
        }

        return answer;
    }
}