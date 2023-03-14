class Solution {
    public int maxKilledEnemies(char[][] grid) {
        int answer = 0;
        Queue<int[]> q = new LinkedList<>();

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == '0') {
                    q.add(new int[] {i, j});
                }
            }
        }

        while (!q.isEmpty()) {
            int[] cell = q.poll();
            int x = cell[0];
            int y = cell[1];

            int cnt = 0;

            //up
            for (int i = x - 1; i >= 0; i--) {
                if (i < 0 || grid[i][y] == 'W') {
                    break;
                }

                if (grid[i][y] == 'E') {
                    cnt++;
                }
            }

            //down
            for (int i = x + 1; i < grid.length; i++) {
                if (i >= grid.length || grid[i][y] == 'W') {
                    break;
                }

                if (grid[i][y] == 'E') {
                    cnt++;
                }
            }

            //left
            for (int i = y - 1; i >= 0; i--) {
                if (i < 0 || grid[x][i] == 'W') {
                    break;
                }

                if (grid[x][i] == 'E') {
                    cnt++;
                }
            }

            //right
            for (int i = y + 1; i < grid[0].length; i++) {
                if (i >= grid[0].length || grid[x][i] == 'W') {
                    break;
                }

                if (grid[x][i] == 'E') {
                    cnt++;
                }
            }

            answer = Math.max(answer, cnt);
        }

        return answer;
    }
}