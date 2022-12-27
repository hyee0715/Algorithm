import java.util.Arrays;

class Solution {
    public int deleteGreatestValue(int[][] grid) {
        int answer = 0;

        for (int i = 0; i < grid.length; i++) {
            Arrays.sort(grid[i]);
        }

        for (int i = grid[0].length - 1; i >= 0; i--) {
            int maxNum = -1;

            for (int j = 0; j < grid.length; j++) {
                maxNum = Math.max(maxNum, grid[j][i]);
                grid[j][i] = -1;
            }

            answer += maxNum;
        }

        return answer;
    }
}