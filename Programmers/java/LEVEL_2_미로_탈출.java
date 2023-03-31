import java.util.*;

class Solution {
    // 한 칸 이동하는 데 1초, 도착 지점까지 걸리는 시간 구하기
    private int bfs(char[][] map, boolean[][] visit, int[] start, int[] end) {
        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};

        Queue<int[]> q = new LinkedList<>(); //x, y, 걸린 시간
        q.add(new int[]{start[0], start[1], 0});
        visit[start[0]][start[1]] = true;

        while (!q.isEmpty()) {
            int[] qx = q.poll();
            int x = qx[0];
            int y = qx[1];
            int cnt = qx[2];

            if (x == end[0] && y == end[1]) {
                return cnt;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= map.length || ny >= map[0].length) {
                    continue;
                }

                if (map[nx][ny] != 'X' && visit[nx][ny] == false) {
                    visit[nx][ny] = true;
                    q.add(new int[]{nx, ny, cnt + 1});
                }
            }
        }

        return -1;
    }

    public int solution(String[] maps) {
        int answer = 0;
        char[][] map = new char[maps.length][maps[0].length()];
        boolean[][] visit = new boolean[maps.length][maps[0].length()];

        int[] start = new int[2];
        int[] end = new int[2];
        int[] lv = new int[2];

        for (int i = 0; i < maps.length; i++) {
            for (int j = 0; j < maps[i].length(); j++) {
                map[i][j] = maps[i].charAt(j);

                if (maps[i].charAt(j) == 'S') {
                    start[0] = i;
                    start[1] = j;
                } else if (maps[i].charAt(j) == 'E') {
                    end[0] = i;
                    end[1] = j;
                } else if (maps[i].charAt(j) == 'L') {
                    lv[0] = i;
                    lv[1] = j;
                }
            }
        }

        //출발점 -> 레버
        answer = bfs(map, visit, start, lv);

        if (answer == -1) {
            return answer;
        }

        visit = new boolean[maps.length][maps[0].length()];
        //레버 -> 도착점
        int n = bfs(map, visit, lv, end);

        if (n == -1) {
            return -1;
        }

        answer += n;
        return answer;
    }
}