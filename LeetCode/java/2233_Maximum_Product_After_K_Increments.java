import java.util.PriorityQueue;

class Solution {
    public int maximumProduct(int[] nums, int k) {
        int answer = 1;

        PriorityQueue<Integer> lo = new PriorityQueue<>();

        for (int n : nums) {
            lo.add(n);
        }

        while (k > 0) {
            int n = lo.poll();
            n++;

            lo.add(n);
            k--;
        }

        while (!lo.isEmpty()) {
            long n = lo.poll() % 1000000007;
            answer = (int)((answer * n) % 1000000007);
        }

        return answer;
    }
}