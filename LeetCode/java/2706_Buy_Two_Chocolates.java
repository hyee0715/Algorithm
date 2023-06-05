import java.util.Arrays;

class Solution {
    public int buyChoco(int[] prices, int money) {
        int answer = money;
        Arrays.sort(prices);

        if (prices[0] + prices[1] > money) {
            return answer;
        }

        answer -= prices[0];
        answer -= prices[1];

        return answer;
    }
}