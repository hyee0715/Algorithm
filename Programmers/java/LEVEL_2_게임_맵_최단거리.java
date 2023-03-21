import java.util.*;

class Solution {
    private int bfs(int[][] maps, boolean[][] visit, int a, int b) {
        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};

        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{a, b, 1});
        visit[a][b] = true;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];
            int cnt = cur[2];

            if (x == maps.length - 1 && y == maps[0].length - 1) {
                return cnt;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= maps.length || ny >= maps[0].length) {
                    continue;
                }

                if (maps[nx][ny] == 1 && visit[nx][ny] == false) {
                    q.add(new int[]{nx, ny, cnt + 1});
                    visit[nx][ny] = true;
                }
            }
        }

        return -1;
    }

    public int solution(int[][] maps) {
        int answer = 0;
        boolean[][] visit = new boolean[maps.length][maps[0].length];

        answer = bfs(maps, visit, 0, 0);
        return answer;
    }
}