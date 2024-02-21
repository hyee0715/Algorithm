import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;

        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for (int n : scoville) {
            pq.add(n);
        }

        while (!pq.isEmpty() && pq.peek() < K) {
            int a = pq.poll();

            if (pq.isEmpty()) {
                answer = -1;
                break;
            }

            int b = pq.poll();

            int mix = a + (b * 2);

            pq.add(mix);

            answer++;
        }

        return answer;
    }
}