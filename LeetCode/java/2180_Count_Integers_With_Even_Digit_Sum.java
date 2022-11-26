class Solution {
    public int countEven(int num) {
        int answer = 0;

        for (int i = 1; i <= num; i++) {
            String s = String.valueOf(i);

            int sum = 0;
            for (int j = 0; j < s.length(); j++) {
                sum += s.charAt(j) - '0';
            }

            if (sum % 2 == 0) {
                answer++;
            }
        }

        return answer;
    }
}