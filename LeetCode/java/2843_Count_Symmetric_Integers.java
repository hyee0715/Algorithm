class Solution {
    public int countSymmetricIntegers(int low, int high) {
        int answer = 0;

        for (int i = low; i <= high; i++) {
            String s = String.valueOf(i);

            if (s.length() % 2 != 0) {
                continue;
            }

            int halfIdx = s.length() / 2;

            int sum1 = 0, sum2 = 0;
            for (int j = 0; j < halfIdx; j++) {
                sum1 += (s.charAt(j) - '0');
            }

            for (int j = halfIdx; j < s.length(); j++) {
                sum2 += (s.charAt(j) - '0');
            }

            if (sum1 == sum2) {
                answer++;
            }
        }

        return answer;
    }
}