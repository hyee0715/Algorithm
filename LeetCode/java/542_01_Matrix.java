import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class Solution {
    private int[][] bfs(int[][] mat, boolean[][] visit, Queue<Cal> q) {
        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};

        int[][] answer = new int[mat.length][mat[0].length];

        for (int i = 0; i < answer.length; i++) {
            Arrays.fill(answer[i], Integer.MAX_VALUE);
        }

        while (!q.isEmpty()) {
            int x = q.peek().getX();
            int y = q.peek().getY();
            int cnt = q.peek().getCount();
            q.poll();

            answer[x][y] = Math.min(answer[x][y], cnt);

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= mat.length || ny >= mat[0].length) {
                    continue;
                }

                if (mat[nx][ny] != 0 && visit[nx][ny] == false) {
                    Cal c = new Cal(nx, ny, cnt + 1);
                    q.add(c);
                    visit[nx][ny] = true;
                }
            }
        }

        return answer;
    }

    public int[][] updateMatrix(int[][] mat) {
        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};

        int[][] answer = new int[mat.length][mat[0].length];
        boolean[][] visit = new boolean[mat.length][mat[0].length];
        Queue<Cal> q = new LinkedList<>();

        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[i].length; j++) {
                if (mat[i][j] == 0) {
                    for (int k = 0; k < 4; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];

                        if (nx < 0 || ny < 0 || nx >= mat.length || ny >= mat[0].length) {
                            continue;
                        }

                        if (mat[nx][ny] == 1 && visit[nx][ny] == false) {
                            Cal c = new Cal(nx, ny, 1);
                            q.add(c);
                            visit[nx][ny] = true;
                        }
                    }
                }
            }
        }

        answer = bfs(mat, visit, q);

        for (int i = 0; i < answer.length; i++) {
            for (int j = 0; j < answer[0].length; j++) {
                if (answer[i][j] == Integer.MAX_VALUE) {
                    answer[i][j] = 0;
                }
            }
        }

        return answer;
    }
}

class Cal {
    int x;
    int y;
    int count;

    Cal(int x, int y, int count) {
        this.x = x;
        this.y = y;
        this.count = count;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    int getCount() {
        return count;
    }
}