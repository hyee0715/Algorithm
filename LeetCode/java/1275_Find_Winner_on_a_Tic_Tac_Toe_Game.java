import java.util.Arrays;

class Solution {
    public String tictactoe(int[][] moves) {
        String answer;
        char[][] board = new char[3][3];

        for (char[] c : board) {
            Arrays.fill(c, 'Z');
        }

        for (int i = 0; i < moves.length; i++) {
            if (i % 2 == 0) {
                board[moves[i][0]][moves[i][1]] = 'X';
            } else {
                board[moves[i][0]][moves[i][1]] = 'O';
            }
        }

        answer = findWinner(board);

        if (answer.equals("A") || answer.equals("B")) {
            return answer;
        }

        if (isDraw(board)) {
            return "Draw";
        }

        return "Pending";
    }

    String findWinner(char[][] board) {
        for (int i = 0; i < board.length; i++) {
            if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == 'X') || (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == 'X')) {
                return "A";
            }
        }

        if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == 'X') || (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == 'X')) {
            return "A";
        }

        for (int i = 0; i < board.length; i++) {
            if ((board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] == 'O') || (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] == 'O')) {
                return "B";
            }
        }

        if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] == 'O') || (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] == 'O')) {
            return "B";
        }

        return "C";
    }

    boolean isDraw(char[][] board) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (board[i][j] == 'Z') {
                    return false;
                }
            }
        }

        return true;
    }
}