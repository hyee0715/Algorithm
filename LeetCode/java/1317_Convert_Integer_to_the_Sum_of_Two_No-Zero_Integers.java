class Solution {
    public int[] getNoZeroIntegers(int n) {
        int[] answer = new int[2];

        for (int i = 1; i < n; i++) {
            if (String.valueOf(i).contains("0") || String.valueOf(n - i).contains("0")) {
                continue;
            }

            answer[0] = i;
            answer[1] = n - i;
            break;
        }

        return answer;
    }
}