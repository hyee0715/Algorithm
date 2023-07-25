import java.util.LinkedList;
import java.util.Queue;

class Solution {
    private void bfs(char[][] board, int i, int j, boolean[][] visit) {
        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};

        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{i, j});
        visit[i][j] = true;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || ny < 0 || nx >= board.length || ny >= board[0].length) {
                    continue;
                }

                if (board[nx][ny] == 'X' && visit[nx][ny] == false) {
                    visit[nx][ny] = true;
                    q.add(new int[]{nx, ny});
                }
            }
        }
    }

    public int countBattleships(char[][] board) {
        int answer = 0;

        boolean[][] visit = new boolean[board.length][board[0].length];

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (board[i][j] == 'X' && visit[i][j] == false) {
                    answer++;
                    bfs(board, i, j, visit);
                }
            }
        }

        return answer;
    }
}