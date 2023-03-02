import java.util.LinkedList;
import java.util.Queue;

class Solution {
    private boolean bfs(int[][] maze, boolean[][] visit, int[] start, int[] destination) {
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        Queue<int[]> q = new LinkedList<>();
        q.add(new int[] {start[0], start[1]});
        visit[start[0]][start[1]] = true;

        while (!q.isEmpty()) {
            int[] pair = q.peek();
            int x = pair[0];
            int y = pair[1];
            q.poll();

            if (x == destination[0] && y == destination[1]) {
                return true;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                while (nx >= 0 && ny >= 0 && nx < maze.length && ny < maze[0].length && maze[nx][ny] != 1) {
                    nx += dx[i];
                    ny += dy[i];
                }

                if (visit[nx - dx[i]][ny - dy[i]] == false) {
                    visit[nx - dx[i]][ny - dy[i]] = true;
                    q.add(new int[]{nx - dx[i], ny - dy[i]});
                }
            }
        }

        return false;
    }

    public boolean hasPath(int[][] maze, int[] start, int[] destination) {
        boolean[][] visit = new boolean[maze.length][maze[0].length];

        return bfs(maze, visit, start, destination);
    }
}