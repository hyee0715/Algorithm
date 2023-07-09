import java.util.PriorityQueue;

class Solution {
    public int largestSumAfterKNegations(int[] nums, int k) {
        int answer = 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for (int n : nums) {
            pq.add(n);
        }

        while (k > 0) {
            int n = pq.poll();

            pq.add(-1 * n);

            k--;
        }

        while (!pq.isEmpty()) {
            answer += pq.poll();
        }

        return answer;
    }
}