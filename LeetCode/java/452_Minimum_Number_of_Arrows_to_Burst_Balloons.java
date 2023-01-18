import java.util.Arrays;
import java.util.Comparator;

class Solution {
    private int getShots(int[][] points, int idx, int answer) {
        if (idx >= points.length - 1) {
            return answer + 1;
        }

        Pair current = new Pair(
                Math.max(points[idx][0], points[idx + 1][0]),
                Math.min(points[idx][1], points[idx + 1][1])
        );

        if (current.getFirst() > current.getSecond()) {
            answer++;
        } else {
            points[idx + 1][0] = current.getFirst();
            points[idx + 1][1] = current.getSecond();
        }

        return answer = getShots(points, idx + 1, answer);
    }

    public int findMinArrowShots(int[][] points) {
        int answer = 0;

        Arrays.sort(points, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[0] - o2[0];
            }
        });

        answer = getShots(points, 0, answer);

        return answer;
    }
}

class Pair {
    int first;
    int second;

    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }

    int getFirst() {
        return first;
    }

    int getSecond() {
        return second;
    }
}