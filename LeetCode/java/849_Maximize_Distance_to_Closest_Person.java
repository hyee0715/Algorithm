import java.util.Collections;
import java.util.PriorityQueue;

class Solution {
    public int maxDistToClosest(int[] seats) {
        PriorityQueue<Integer> hi = new PriorityQueue<>(Collections.reverseOrder());
        int answer = 0;
        int zeroCnt = 0;

        int idx = 0, revIdx = seats.length - 1;

        if (seats[0] == 0) {
            while (seats[idx] == 0) {
                zeroCnt++;
                idx++;
            }

            hi.add(zeroCnt);
            zeroCnt = 0;
        }

        if (seats[revIdx] == 0) {
            while (seats[revIdx] == 0) {
                zeroCnt++;
                revIdx--;
            }

            hi.add(zeroCnt);
            zeroCnt = 0;
        }

        for (int i = idx; i < revIdx; i++) {
            if (seats[i] == seats[i + 1] && seats[i] == 0) {
                if (zeroCnt == 0) {
                    zeroCnt++;
                }

                zeroCnt++;
            } else {
                if (zeroCnt <= 2) {
                    hi.add(1);
                    zeroCnt = 0;
                    continue;
                }

                if (zeroCnt % 2 == 0) {
                    hi.add(zeroCnt / 2);
                } else {
                    hi.add(zeroCnt / 2 + 1);
                }

                zeroCnt = 0;
            }
        }

        if (zeroCnt != 0) {
            if (zeroCnt % 2 == 0) {
                hi.add(zeroCnt / 2);
            } else {
                hi.add(zeroCnt / 2 + 1);
            }
        }

        answer = hi.peek();

        return answer;
    }
}