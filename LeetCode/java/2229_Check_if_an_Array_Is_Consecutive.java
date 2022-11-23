import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class Solution {
    public boolean isConsecutive(int[] nums) {
        Set<Integer> set = new HashSet<>();

        Arrays.sort(nums);

        for (int i = 0; i < nums.length; i++) {
            set.add(nums[i]);
        }

        int start = nums[0];
        int end = nums[0] + nums.length - 1;

        for (int i = start; i <= end; i++) {
            if (!set.contains(i)) {
                return false;
            }
        }

        return true;
    }
}