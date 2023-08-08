import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    public int[][] sortTheStudents(int[][] score, int k) {
        int[][] answer = new int[score.length][score[0].length];

        List<int[]> list = new ArrayList<>();

        for (int i = 0; i < score.length; i++) {
            list.add(new int[] {score[i][k], i});
        }

        Collections.sort(list, (x, y) -> {
            if (x[0] < y[0]) {
                return 1;
            }

            if (x[0] > y[0]) {
                return -1;
            }

            return 0;
        });

        int row = 0;

        for (int[] p : list) {
            for (int i = 0; i < score[0].length; i++) {
                answer[row][i] = score[p[1]][i];
            }

            row++;
        }

        return answer;
    }
}