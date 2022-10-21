class Solution {
    public int countQuadruplets(int[] nums) {
        int answer = 0;

        for (int i = 0; i < nums.length - 3; i++) {
            for (int j = i + 1; j < nums.length - 2; j++) {
                for (int k = j + 1; k < nums.length - 1; k++) {
                    for (int a = k + 1; a < nums.length; a++) {
                        if (nums[i] + nums[j] + nums[k] == nums[a]) {
                            answer++;
                        }
                    }
                }
            }
        }

        return answer;
    }
}