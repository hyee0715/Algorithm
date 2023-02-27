import java.util.Arrays;

class Solution {
    private boolean dfs(char[][] board, String word, boolean[][] visit, int x, int y, int idx) {
        if (idx == word.length()) {
            return true;
        }

        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= board.length || ny >= board[0].length) {
                continue;
            }

            if (board[nx][ny] == word.charAt(idx) && visit[nx][ny] == false) {
                visit[nx][ny] = true;
                if (dfs(board, word, visit, nx, ny, idx + 1)) {
                    return true;
                }
                visit[nx][ny] = false;
            }
        }

        return false;
    }

    public boolean exist(char[][] board, String word) {
        boolean[][] visit = new boolean[board.length][board[0].length];

        for (int i = 0; i < visit.length; i++) {
            Arrays.fill(visit[i], false);
        }

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (board[i][j] == word.charAt(0)) {

                    for (int k = 0; k < visit.length; k++) {
                        Arrays.fill(visit[k], false);
                    }

                    visit[i][j] = true;
                    if (dfs(board, word, visit, i, j, 1)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
}