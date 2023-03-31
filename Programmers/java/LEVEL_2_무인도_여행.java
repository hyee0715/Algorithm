import java.util.*;

class Solution {
    int[] dx = {0, 0, -1, 1};
    int[] dy = {-1, 1, 0, 0};

    private int bfs(int[][] map, boolean[][] visit, int a, int b) {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{a, b});
        visit[a][b] = true;

        int sum = 0;

        while (!q.isEmpty()) {
            int[] qx = q.poll();
            int x = qx[0];
            int y = qx[1];

            sum += map[x][y];

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= map.length || ny >= map[0].length) {
                    continue;
                }

                if (map[nx][ny] != -1 && visit[nx][ny] == false) {
                    q.add(new int[]{nx, ny});
                    visit[nx][ny] = true;
                }
            }
        }

        return sum;
    }

    public int[] solution(String[] maps) {
        int[] answer = {};
        List<Integer> lands = new ArrayList<>();

        int[][] map = new int[maps.length][maps[0].length()];
        boolean[][] visit = new boolean[maps.length][maps[0].length()];

        for (int i = 0; i < maps.length; i++) {
            for (int j = 0; j < maps[i].length(); j++) {
                if (maps[i].charAt(j) == 'X') {
                    map[i][j] = -1;
                    continue;
                }

                map[i][j] = maps[i].charAt(j) - '0';
            }
        }

        for (int i = 0; i < map.length; i++) {
            for (int j = 0; j < map[i].length; j++) {
                if (map[i][j] != -1 && visit[i][j] == false) {
                    int n = bfs(map, visit, i, j);
                    lands.add(n);
                }
            }
        }

        if (lands.isEmpty()) {
            answer = new int[]{-1};
            return answer;
        }

        answer = new int[lands.size()];

        for (int i = 0; i < lands.size(); i++) {
            answer[i] = lands.get(i);
        }

        Arrays.sort(answer);

        return answer;
    }
}