import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class Solution {
    public int findMaxK(int[] nums) {
        int answer = -1;
        Set<Integer> set = new HashSet<>();

        for (int n : nums) {
            set.add(n);
        }

        Arrays.sort(nums);

        for (int i = nums.length - 1; i >= 0; i--) {
            int negative = nums[i] * -1;

            if (set.contains(negative)) {
                answer = nums[i];
                break;
            }
        }

        return answer;
    }
}