import java.util.LinkedList;
import java.util.Queue;

class Solution {
    private int check(int[][] grid, boolean[][] visit, int a, int b) {
        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};

        Queue<int[]> q = new LinkedList<>();
        q.add(new int[] {a, b});
        visit[a][b] = true;

        int cnt = 0;
        boolean boundary = false;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];

            cnt++;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= grid.length || ny >= grid[0].length) {
                    if (grid[x][y] == 1) {
                        boundary = true;
                    }

                    continue;
                }

                if (grid[nx][ny] == 1 && visit[nx][ny] == false) {
                    q.add(new int[] {nx ,ny});
                    visit[nx][ny] = true;
                }
            }
        }

        if (boundary) {
            return 0;
        }

        return cnt;
    }

    public int numEnclaves(int[][] grid) {
        boolean[][] visit = new boolean[grid.length][grid[0].length];
        int answer = 0;

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 1 && visit[i][j] == false) {
                    answer += check(grid, visit, i, j);
                }
            }
        }

        return answer;
    }
}