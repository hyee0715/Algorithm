import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class Solution {
    public int longestSquareStreak(int[] nums) {
        int answer = -1;

        Arrays.sort(nums);

        Set<Integer> set = new HashSet<>();

        for (int n : nums) {
            set.add(n);
        }

        for (int i = 0; i < nums.length; i++) {
            int cnt = 1;
            int n = nums[i];

            while (true) {
                if ((long)n * n > 100000) {
                    break;
                }

                n = n * n;

                if (!set.contains(n)) {
                    break;
                }

                if (set.contains(n)) {
                    cnt++;

                    if (cnt > 1) {
                        answer = Math.max(answer, cnt);
                    }
                }
            }
        }

        return answer;
    }
}