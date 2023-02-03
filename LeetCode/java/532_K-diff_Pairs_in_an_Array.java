import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class Solution {
    public int findPairs(int[] nums, int k) {
        Set<Integer> set = new HashSet<>();
        int answer = 0;

        Arrays.sort(nums);

        for (int i = 0; i < nums.length; i++) {
            if (i < nums.length - 1 && nums[i] == nums[i + 1]) {
                if (i < nums.length - 2 && nums[i + 1] == nums[i + 2]) {
                    continue;
                }

                if (k == 0 && !set.contains(nums[i])) {
                    answer++;
                }

                continue;
            }

            if (set.contains(nums[i])) {
                answer++;
            }

            set.add(k + nums[i]);
        }

        return answer;
    }
}