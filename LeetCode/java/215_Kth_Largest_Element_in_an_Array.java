import java.util.Collections;
import java.util.PriorityQueue;

class Solution {
    public int findKthLargest(int[] nums, int k) {
        PriorityQueue<Integer> hi = new PriorityQueue<>(Collections.reverseOrder());
        int answer = 0;

        for (int n : nums) {
            hi.add(n);
        }

        for (int i = 0; i < k; i++) {
            answer = hi.poll();
        }

        return answer;
    }
}