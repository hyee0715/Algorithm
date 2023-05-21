class Solution {
    public int[] shuffle(int[] nums, int n) {
        int[] answer = new int[nums.length];

        int idx = 0;

        for (int i = 0; i < n; i++) {
            answer[idx++] = nums[i];
            answer[idx++] = nums[i + n];
        }

        return answer;
    }
}