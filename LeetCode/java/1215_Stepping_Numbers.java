import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution {
    public List<Integer> countSteppingNumbers(int low, int high) {
        List<Integer> answer = new ArrayList<>();

        Queue<Long> q = new LinkedList<>();

        if (low == 0) {
            answer.add(0);
        }

        for (long i = 1; i <= 9; i++) {
            q.add(i);
        }

        while (!q.isEmpty()) {
            long n = q.poll();

            if (n < high) {
                long last = n % 10;

                if (last > 0) {
                    long next = n * 10 + last - 1;
                    q.add(next);
                }

                if (last < 9) {
                    long next = n * 10 + last + 1;
                    q.add(next);
                }
            }

            if (n >= low && n <= high) {
                answer.add((int)n);
            }
        }

        return answer;
    }
}