import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

class Solution {
    private int[] check(int a, int b, boolean isUpDirection, int[][] mat) {
        int[] answer = new int[mat.length * mat[0].length];
        int idx = 0;

        int[] upDirX = {1, 0};
        int[] upDirY = {0, 1};

        int[] downDirX = {0, 1};
        int[] downDirY = {1, 0};

        Stack<int[]> stack = new Stack<>();
        Queue<int[]> q = new LinkedList<>();
        boolean[][] visit = new boolean[mat.length][mat[0].length];
        q.add(new int[]{a, b});
        visit[a][b] = true;

        while (!q.isEmpty()) {
            int qSize = q.size();

            for (int k = 0; k < qSize; k++) {
                int[] cur = q.poll();
                int x = cur[0];
                int y = cur[1];

                answer[idx++] = mat[x][y];

                for (int i = 0; i < 2; i++) {
                    int nx, ny;

                    if (isUpDirection) {
                        nx = x + upDirX[i];
                        ny = y + upDirY[i];
                    } else {
                        nx = x + downDirX[i];
                        ny = y + downDirY[i];
                    }

                    if (nx < 0 || ny < 0 || nx >= mat.length || ny >= mat[0].length) {
                        continue;
                    }

                    if (visit[nx][ny] == false) {
                        visit[nx][ny] = true;
                        stack.push(new int[] {nx, ny});
                    }
                }
            }

            while (!stack.isEmpty()) {
                q.add(stack.pop());
            }

            if (isUpDirection) {
                isUpDirection = false;
            } else {
                isUpDirection = true;
            }
        }

        return answer;
    }

    public int[] findDiagonalOrder(int[][] mat) {
        return check(0, 0, true, mat);
    }
}