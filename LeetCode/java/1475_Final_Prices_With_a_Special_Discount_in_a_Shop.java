class Solution {
    public int[] finalPrices(int[] prices) {
        int[] answer = new int[prices.length];
        int idx = 0;

        for (int i = 0; i < prices.length; i++) {
            boolean flag = false;

            for (int j = i + 1; j < prices.length; j++) {
                if (prices[i] >= prices[j]) {
                    answer[idx] = prices[i] - prices[j];
                    flag = true;
                    break;
                }
            }

            if (!flag) {
                answer[idx] = prices[i];
            }

            idx++;
        }

        return answer;
    }
}