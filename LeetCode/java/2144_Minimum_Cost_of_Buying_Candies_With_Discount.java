import java.util.Arrays;

class Solution {
    public int minimumCost(int[] cost) {
        int answer = 0;

        Arrays.sort(cost);

        for (int i = 0; i < cost.length; i++) {
            if (i % 3 == 2) {
                continue;
            }

            answer += cost[cost.length - i - 1];
        }

        return answer;
    }
}