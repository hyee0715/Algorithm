import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution {
    private boolean nothingChanged(int[][] board, int[][] prevBoard) {
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (board[i][j] != prevBoard[i][j]) {
                    return false;
                }
            }
        }

        return true;
    }

    public int[][] candyCrush(int[][] board) {
        boolean[][] visit = new boolean[board.length][board[0].length];
        Queue<List<Pair>> blocksQueue = new LinkedList<>();
        Queue<Pair> zeroQueue = new LinkedList<>();
        int[][] prevBoard = new int[board.length][board[0].length];

        while (true) {
            for (int i = 0; i < board.length; i++) {
                for (int j = 0; j < board[i].length; j++) {
                    prevBoard[i][j] = board[i][j];
                }
            }

            //가로 탐색
            for (int i = 0; i < board.length; i++) {
                List<Pair> temp = new ArrayList<>();

                for (int j = 0; j < board[i].length - 1; j++) {
                    if (board[i][j] == board[i][j + 1]) {
                        if (temp.isEmpty()) {
                            temp.add(new Pair(i, j));
                        }

                        temp.add(new Pair(i, j + 1));
                    } else {
                        if (!temp.isEmpty() && temp.size() >= 3) {
                            blocksQueue.add(new ArrayList<Pair>(temp));
                        }

                        temp.clear();
                    }
                }

                if (!temp.isEmpty() && temp.size() >= 3) {
                    blocksQueue.add(new ArrayList<Pair>(temp));

                    temp.clear();
                }
            }

            //세로 탐색
            for (int i = 0; i < board[0].length; i++) {
                List<Pair> temp = new ArrayList<>();

                for (int j = 0; j < board.length - 1; j++) {
                    if (board[j][i] == board[j + 1][i]) {
                        if (temp.isEmpty()) {
                            temp.add(new Pair(j, i));
                        }

                        temp.add(new Pair(j + 1, i));
                    } else {
                        if (!temp.isEmpty() && temp.size() >= 3) {
                            blocksQueue.add(new ArrayList<Pair>(temp));
                        }

                        temp.clear();
                    }
                }

                if (!temp.isEmpty() && temp.size() >= 3) {
                    blocksQueue.add(new ArrayList<Pair>(temp));

                    temp.clear();
                }
            }

            //사탕 비우기
            while (!blocksQueue.isEmpty()) {
                List<Pair> front = blocksQueue.poll();
                List<Pair> list = new ArrayList<>(front);

                for (int i = 0; i < list.size(); i++) {
                    int x = list.get(i).getX();
                    int y = list.get(i).getY();

                    board[x][y] = 0;
                }
            }

            //사탕 아래로 떨어뜨리기
            for (int i = 0; i < board[0].length; i++) {
                while (!zeroQueue.isEmpty()) {
                    zeroQueue.poll();
                }

                for (int j = board.length - 1; j >= 0; j--) {
                    if (board[j][i] == 0) {
                        zeroQueue.add(new Pair(i, j));
                    }

                    if (board[j][i] != 0 && !zeroQueue.isEmpty()) {
                        int x = zeroQueue.peek().getY();
                        int y = zeroQueue.peek().getX();
                        zeroQueue.poll();

                        board[x][y] = board[j][i];
                        board[j][i] = 0;

                        zeroQueue.add(new Pair(i, j));
                    }
                }
            }

            if (nothingChanged(board, prevBoard)) {
                break;
            }
        }

        return board;
    }
}

class Pair {
    int x;
    int y;

    Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }
}