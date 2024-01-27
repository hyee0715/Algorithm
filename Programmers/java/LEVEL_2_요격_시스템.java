import java.util.*;

class Solution {
    public int solution(int[][] targets) {
        int answer = 0;

        sortTargets(targets);

        int[] cur = new int[]{targets[0][0], targets[0][1]};

        for (int i = 0; i < targets.length; i++) {
            if (targets[i][0] < cur[1]) {
                cur[0] = Math.max(cur[0], targets[i][0]);
                cur[1] = Math.min(cur[1], targets[i][1]);
            } else {
                answer++;
                cur = new int[]{targets[i][0], targets[i][1]};
            }
        }

        answer++;

        return answer;
    }

    private void sortTargets(int[][] targets) {
        Arrays.sort(targets, (x, y) -> {
            if (x[1] < y[1]) {
                return -1;
            }

            if (x[1] > y[1]) {
                return 1;
            }

            if (x[0] < y[1]) {
                return -1;
            }

            if (x[0] > y[0]) {
                return 1;
            }

            return 0;
        });
    }
}