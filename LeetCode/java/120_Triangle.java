import java.util.List;

class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int answer = Integer.MAX_VALUE;
        int[][] dp = new int[200][200];

        if (triangle.size() == 1) {
            return triangle.get(0).get(0);
        } else if (triangle.size() == 2) {
            answer = Math.min(triangle.get(0).get(0) + triangle.get(1).get(0), triangle.get(0).get(0) + triangle.get(1).get(1));
            return answer;
        }

        dp[0][0] = triangle.get(0).get(0);
        dp[1][0] = dp[0][0] + triangle.get(1).get(0);
        dp[1][1] = dp[0][0] + triangle.get(1).get(1);

        for (int i = 2; i < triangle.size(); i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + triangle.get(i).get(j);
                } else if (j == i) {
                    dp[i][j] = dp[i - 1][j - 1] + triangle.get(i).get(j);
                } else {
                    dp[i][j] = Math.min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle.get(i).get(j);
                }
            }
        }

        for (int i = 0; i < triangle.get(triangle.size() - 1).size(); i++) {
            answer = Math.min(answer, dp[triangle.size() - 1][i]);
        }

        return answer;
    }
}