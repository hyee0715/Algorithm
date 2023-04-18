import java.util.LinkedList;
import java.util.Queue;

class Solution {
    private void bfs(char[][] board, boolean[][] visit, int a, int b) {
        int[] dx = {0, 0, -1, 1};
        int[] dy = {-1, 1, 0, 0};

        Queue<int[]> q = new LinkedList<>();
        Queue<int[]> nonFlip = new LinkedList<>();

        q.add(new int[] {a, b});
        nonFlip.add(new int[] {a, b});
        board[a][b] = 'X';
        visit[a][b] = true;

        boolean onTheBoarder = false;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];

            if (x == 0 || x == board.length - 1 || y == 0 || y == board[0].length - 1) {
                onTheBoarder = true;
            }

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= board.length || ny >= board[0].length) {
                    continue;
                }

                if (board[nx][ny] == 'O' && visit[nx][ny] == false) {
                    q.add(new int[] {nx, ny});
                    visit[nx][ny] = true;
                    board[nx][ny] = 'X';

                    nonFlip.add(new int[] {nx, ny});
                }
            }
        }

        if (onTheBoarder) {
            while (!nonFlip.isEmpty()) {
                int[] cur = nonFlip.poll();
                int x = cur[0];
                int y = cur[1];

                board[x][y] = 'O';
            }
        }
    }

    public void solve(char[][] board) {
        boolean[][] visit = new boolean[board.length][board[0].length];

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (board[i][j] == 'O' && visit[i][j] == false) {
                    bfs(board, visit, i, j);
                }
            }
        }
    }
}