import java.util.PriorityQueue;

class Solution {
    public int connectSticks(int[] sticks) {
        int answer = 0, sum = 0;
        if (sticks.length == 1) {
            return answer;
        }

        if (sticks.length == 2) {
            answer = sticks[0] + sticks[1];
            return answer;
        }

        PriorityQueue<Integer> lo = new PriorityQueue<>();

        for (int n : sticks) {
            lo.add(n);
        }

        while (lo.size() > 1) {
            int a = 0, b = 0;

            if (!lo.isEmpty()) {
                a = lo.poll();
            }

            if (!lo.isEmpty()) {
                b = lo.poll();
            }

            sum = a + b;
            answer += sum;

            lo.add(sum);
        }

        return answer;
    }
}