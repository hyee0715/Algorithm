import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class Solution {
    private void bfs(int[][] rooms, Queue<Pair> q, boolean[][] visit) {
        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};

        while (!q.isEmpty()) {
            int x = q.peek().getX();
            int y = q.peek().getY();
            q.poll();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= rooms.length || ny >= rooms[0].length) continue;

                if (rooms[nx][ny] != -1 && visit[nx][ny] == false) {
                    Pair p = new Pair(nx, ny);
                    q.add(p);
                    visit[nx][ny] = true;
                    rooms[nx][ny] = Math.min(rooms[nx][ny], rooms[x][y] + 1);
                }
            }
        }
    }

    public void wallsAndGates(int[][] rooms) {
        Queue<Pair> q = new LinkedList<>();
        boolean[][] visit = new boolean[rooms.length][rooms[0].length];

        for (int i = 0; i < visit.length; i++) {
            Arrays.fill(visit[i], false);
        }

        for (int i = 0; i < rooms.length; i++) {
            for (int j = 0; j < rooms[i].length; j++) {
                if (rooms[i][j] == 0) {
                    Pair p = new Pair(i, j);
                    q.add(p);
                    visit[i][j] = true;
                }
            }
        }

        bfs(rooms, q, visit);
    }
}

class Pair {
    int x;
    int y;

    Pair (int x, int y) {
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