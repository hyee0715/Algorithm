class Solution {
    public int[][] onesMinusZeros(int[][] grid) {
        int[][] answer = new int[grid.length][grid[0].length];

        int[] onesRow = new int[grid.length];
        int[] zerosRow = new int[grid.length];
        int[] onesCol = new int[grid[0].length];
        int[] zerosCol = new int[grid[0].length];

        for (int i = 0; i < grid.length; i++) {
            int oneCnt = 0, zeroCnt = 0;

            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 0) {
                    zeroCnt++;
                } else {
                    oneCnt++;
                }
            }

            onesRow[i] = oneCnt;
            zerosRow[i] = zeroCnt;
        }

        for (int i = 0; i < grid[0].length; i++) {
                int oneCnt = 0, zeroCnt = 0;

            for (int j = 0; j < grid.length; j++) {
                if (grid[j][i] == 0) {
                    zeroCnt++;
                } else {
                    oneCnt++;
                }
            }

            onesCol[i] = oneCnt;
            zerosCol[i] = zeroCnt;
        }

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                answer[i][j] = onesRow[i] + onesCol[j] - zerosRow[i] - zerosCol[j];
            }
        }

        return answer;
    }
}