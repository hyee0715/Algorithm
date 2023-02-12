import java.util.*;

class Solution {
    public long solution(int n, int[] works) {
        long answer = 0;
        PriorityQueue<Integer> hi = new PriorityQueue<>(Collections.reverseOrder());

        for (int num : works) {
            hi.add(num);
        }

        while (n > 0) {
            if (hi.isEmpty()) {
                break;
            }

            int num = hi.peek();
            hi.poll();

            num--;
            if (num > 0) {
                hi.add(num);
            }

            n--;
        }

        while (!hi.isEmpty()) {
            answer += (hi.peek() * hi.peek());
            hi.poll();
        }

        return answer;
    }
}