import java.util.*;

class Solution {
    int MOD = 20170805;

    int[] dx = {0, 1}; //오른쪽 0, 아래 1
    int[] dy = {1, 0};

    private int dfs(int[][] cityMap, boolean[][] visit, int endX, int endY, int dir, int x, int y, int[][][] memo) {
        if (x == endX && y == endY) {
            return 1;
        }

        if (memo[x][y][dir] != -1) {
            return memo[x][y][dir];
        }

        memo[x][y][dir] = 0;

        if (cityMap[x][y] == 0) { //자동차 자유롭게 통행
            for (int i = 0; i < 2; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= cityMap.length || ny >= cityMap[0].length) {
                    continue;
                }

                if (cityMap[nx][ny] != 1 && visit[nx][ny] == false) {
                    visit[nx][ny] = true;
                    memo[x][y][dir] += (dfs(cityMap, visit, endX, endY, i, nx, ny, memo)) % MOD;
                    visit[nx][ny] = false;
                }
            }
        }

        if (cityMap[x][y] == 2) { //이전 방향대로만 이동 가능
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx >= 0 && ny >= 0 && nx < cityMap.length && ny < cityMap[0].length) {
                if (cityMap[nx][ny] != 1 && visit[nx][ny] == false) {
                    visit[nx][ny] = true;
                    memo[x][y][dir] += (dfs(cityMap, visit, endX, endY, dir, nx, ny, memo) % MOD);
                    visit[nx][ny] = false;
                }
            }
        }

        return memo[x][y][dir] % MOD;
    }

    public int solution(int m, int n, int[][] cityMap) {
        int answer = 0;

        boolean[][] visit = new boolean[cityMap.length][cityMap[0].length];
        int[][][] memo = new int[cityMap.length][cityMap[0].length][2];

        for (int i = 0; i < memo.length; i++) {
            for (int j = 0; j < memo[i].length; j++) {
                Arrays.fill(memo[i][j], -1);
            }
        }

        answer = dfs(cityMap, visit, m - 1, n - 1, 0, 0, 0, memo);

        return answer;
    }
}