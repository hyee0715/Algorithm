import java.util.LinkedList;
import java.util.Queue;

class Solution {
    private int check(int[][] board, int x, int y) {
        int[] dx = {0, 0, 1, -1, -1, -1, 1, 1};
        int[] dy = {1, -1, 0, 0, -1, 1, -1, 1};

        int cnt = 0;

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= board.length || ny >= board[0].length) {
                continue;
            }

            if (board[nx][ny] == 1) {
                cnt++;
            }
        }

        return cnt;
    }

    public void gameOfLife(int[][] board) {
        Queue<Integer> q = new LinkedList<>();

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                int neighbors = check(board, i, j);

                if (board[i][j] == 1) {
                    if (neighbors == 2 || neighbors == 3) {
                        q.add(1);
                    } else {
                        q.add(0);
                    }
                } else {
                    if (neighbors == 3) {
                        q.add(1);
                    } else {
                        q.add(0);
                    }
                }
            }
        }

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                board[i][j] = q.poll();
            }
        }
    }
}