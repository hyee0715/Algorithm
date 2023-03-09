class Solution {
    int check(int[][] board, Integer[][] memo, int curN, int curM) {
        if (curN >= board.length || curM >= board[0].length) {
            return 0;
        }

        if (board[curN][curM] == -1) {
            return 0;
        }

        if (curN == board.length - 1 && curM == board[0].length - 1) {
            return 1;
        }

        if (memo[curN][curM] != null) {
            return memo[curN][curM];
        }

        return memo[curN][curM] = (check(board, memo, curN + 1, curM) % 1000000007 + check(board, memo, curN, curM + 1) % 1000000007) % 1000000007;
    }

    public int solution(int m, int n, int[][] puddles) {
        int answer = 0;

        Integer[][] memo = new Integer[n][m];
        int[][] board = new int[n][m];

        for (int i = 0; i < puddles.length; i++) {
            int x = puddles[i][1];
            int y = puddles[i][0];

            board[x - 1][y - 1] = -1;
        }

        answer = check(board, memo, 0, 0);

        return answer;
    }
}