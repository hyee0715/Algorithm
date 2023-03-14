import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class Solution {
    public int minMoves(int[] nums) {
        int answer = 0;

        Arrays.sort(nums);

        for (int i = 1; i < nums.length; i++) {
            answer += (nums[i] - nums[0]);
        }

        return answer;
    }
}