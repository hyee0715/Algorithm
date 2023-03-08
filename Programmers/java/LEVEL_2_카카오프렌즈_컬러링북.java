import java.util.*;

class Solution {
    //영역 크기 리턴
    private int bfs(int a, int b, int[][] picture, boolean[][] visit) {
        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};

        int area = 0;

        Queue<int[]> q = new LinkedList<>();
        q.add(new int[] {a, b});
        visit[a][b] = true;

        while (!q.isEmpty()) {
            int[] element = q.poll();
            int x = element[0];
            int y = element[1];

            area++;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= picture.length || ny >= picture[0].length) {
                    continue;
                }

                if (picture[nx][ny] == picture[x][y] && visit[nx][ny] == false) {
                    visit[nx][ny] = true;
                    q.add(new int[] {nx, ny});
                }
            }
        }

        return area;
    }

    public int[] solution(int m, int n, int[][] picture) {
        int numberOfArea = 0;
        int maxSizeOfOneArea = 0;

        int[] answer = new int[2];
        boolean[][] visit = new boolean[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (picture[i][j] != 0 && visit[i][j] == false) {
                    numberOfArea++;
                    maxSizeOfOneArea = Math.max(maxSizeOfOneArea, bfs(i, j, picture, visit));
                }
            }
        }

        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;

        return answer;
    }
}