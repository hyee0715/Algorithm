import java.util.*;

class Solution {
    public int[] solution(String[] operations) {
        int[] answer = {0, 0};
        PriorityQueue<Integer> hi = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> lo = new PriorityQueue<>();

        for (int i = 0; i < operations.length; i++) {
            String[] operation = operations[i].split(" ");
            String op = operation[0];
            int num = Integer.parseInt(operation[1]);

            if (op.equals("I")) {
                hi.add(num);
                continue;
            }

            if (op.equals("D")) {
                if (num == 1) {
                    if (!hi.isEmpty()) {
                        hi.poll();
                    }

                    continue;
                }

                if (num == -1) {
                    while (!hi.isEmpty()) {
                        lo.add(hi.poll());
                    }

                    if (lo.isEmpty()) {
                        continue;
                    }

                    lo.poll();

                    while (!lo.isEmpty()) {
                        hi.add(lo.poll());
                    }
                }
            }
        }

        if (hi.isEmpty()) {
            return answer;
        }

        answer[0] = hi.peek();

        while (!hi.isEmpty()) {
            lo.add(hi.poll());
        }

        answer[1] = lo.peek();

        return answer;
    }
}