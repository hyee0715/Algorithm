import java.util.PriorityQueue;

class Solution {
    public int minimumOperations(int[] nums) {
        PriorityQueue<Integer> lo = new PriorityQueue<>();
        PriorityQueue<Integer> lo2 = new PriorityQueue<>();
        int answer = 0;

        for (int n : nums) {
            lo.add(n);
        }

        while (!lo.isEmpty()) {
            int minNum = lo.poll();

            while (minNum == 0 && !lo.isEmpty()) {
                minNum = lo.poll();
            }

            if (minNum == 0 && lo.isEmpty()) {
                break;
            }

            answer++;

            while (!lo.isEmpty()) {
                lo2.add(lo.poll() - minNum);
            }

            while (!lo2.isEmpty()) {
                lo.add(lo2.poll());
            }
        }

        return answer;
    }
}