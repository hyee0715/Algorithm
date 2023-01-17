import java.util.Collections;
import java.util.PriorityQueue;

class Solution {
    public int[][] largestLocal(int[][] grid) {
        int[][] answer = new int[grid.length - 2][grid[0].length - 2];
        PriorityQueue<Integer> q = new PriorityQueue<>(Collections.reverseOrder());

        for (int i = 0; i < grid.length - 2; i++) {
            for (int j = 0; j < grid[i].length - 2; j++) {
                q.clear();

                for (int a = 0; a < 3; a++) {
                    for (int b = 0; b < 3; b++) {
                        q.add(grid[i + a][j + b]);
                    }
                }

                answer[i][j] = q.poll();
            }
        }

        return answer;
    }
}