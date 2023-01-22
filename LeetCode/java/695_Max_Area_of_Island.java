import java.util.LinkedList;
import java.util.Queue;

class Solution {
    int area = 0;

    private void bfs(int[][] grid, boolean[][] visit, int a, int b) {
        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};

        Queue<Pair> q = new LinkedList<>();
        Pair pair = new Pair(a, b);
        q.add(pair);
        visit[a][b] = true;

        while (!q.isEmpty()) {
            int x = q.peek().getX();
            int y = q.peek().getY();
            q.poll();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= grid.length || ny >= grid[0].length) continue;

                if (grid[nx][ny] == 1 && visit[nx][ny] == false) {
                    area++;
                    Pair p = new Pair(nx, ny);
                    q.add(p);
                    visit[nx][ny] = true;
                }
            }
        }
    }

    public int maxAreaOfIsland(int[][] grid) {
        int answer = 0;
        boolean [][] visit = new boolean[grid.length][grid[0].length];

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 1 && !visit[i][j]) {
                    area = 1;
                    bfs(grid, visit, i, j);
                    answer = Math.max(answer, area);
                }
            }
        }

        return answer;
    }
}

class Pair {
    int x;
    int y;

    Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }
}