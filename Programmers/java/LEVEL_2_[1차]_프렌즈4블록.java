import java.util.*;

class Solution {
    public int solution(int m, int n, String[] board) {
        int answer = 0;

        char[][] map = settingMap(board);
        Queue<int[]> q = new LinkedList<>(); //없애야 할 블록 x, y 좌표

        findSameFourBlocks(map, q);

        while (!q.isEmpty()) {
            deleteBlocks(map, q);

            dropBlocks(map);

            findSameFourBlocks(map, q);
        }

        int deletedCnt = countDeletedBlocks(map);
        answer = deletedCnt;

        return answer;
    }

    private char[][] settingMap(String[] board) {
        char[][] map = new char[board.length][board[0].length()];

        int idx = 0;
        for (String s : board) {
            char[] list = new char[s.length()];

            for (int i = 0; i < s.length(); i++) {
                map[idx][i] = s.charAt(i);
            }

            idx++;
        }

        return map;
    }

    private void findSameFourBlocks(char[][] map, Queue<int[]> q) {
        for (int i = 0; i < map.length - 1; i++) {
            for (int j = 0; j < map[i].length - 1; j++) {
                if (map[i][j] != '*' && map[i][j] == map[i + 1][j] && map[i][j] == map[i][j + 1] && map[i][j] == map[i + 1][j + 1]) {
                    q.add(new int[]{i, j});
                    q.add(new int[]{i + 1, j});
                    q.add(new int[]{i, j + 1});
                    q.add(new int[]{i + 1, j + 1});
                }
            }
        }
    }

    private void deleteBlocks(char[][] map, Queue<int[]> q) {
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];

            if (map[x][y] != '*') {
                map[x][y] = '*';
            }
        }
    }

    private void dropBlock(char[][] map, int column) {
        Queue<Character> q = new LinkedList<>();

        for (int i = map.length - 1; i >= 0; i--) {
            if (map[i][column] != '*') {
                q.add(map[i][column]);
            }
        }

        int qSize = q.size();
        int row = map.length - 1;

        while (!q.isEmpty()) {
            map[row][column] = q.poll();

            row--;
        }

        for (int i = 0; i < map.length - qSize; i++) {
            map[i][column] = '*';
        }
    }

    private void dropBlocks(char[][] map) {
        for (int j = 0; j < map[0].length; j++) {
            dropBlock(map, j);
        }
    }

    private int countDeletedBlocks(char[][] map) {
        int cnt = 0;

        for (char[] c : map) {
            for (char cc : c) {
                if (cc == '*') {
                    cnt++;
                }
            }
        }

        return cnt;
    }
}