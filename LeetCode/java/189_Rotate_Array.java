import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    public void rotate(int[] nums, int k) {
        Deque<Integer> dq = new ArrayDeque<>();

        for (int n : nums) {
            dq.addLast(n);
        }

        for (int i = 0; i < k; i++) {
            int num = dq.pollLast();

            dq.addFirst(num);
        }

        int idx = 0;
        while (!dq.isEmpty()) {
            nums[idx] = dq.pollFirst();
            idx++;
        }
    }
}