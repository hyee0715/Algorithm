class Solution {
    public boolean findSubarrays(int[] nums) {
        Set<Integer> set = new HashSet<>();

        for (int i = 0; i < nums.length - 1; i++) {
            int sum = 0;
            sum += nums[i];
            sum += nums[i + 1];

            if (set.contains(sum)) {
                return true;
            }

            if (!set.contains(sum)) {
                set.add(sum);
            }
        }

        return false;
    }
}