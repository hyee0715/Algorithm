class Solution {
    public int maxProduct(int[] nums) {
        int answer = -1;

        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < nums.length; j++) {
                if (i != j) {
                    int cal = (nums[i] - 1) * (nums[j] - 1);

                    answer = Math.max(answer, cal);
                }
            }
        }

        return answer;
    }
}