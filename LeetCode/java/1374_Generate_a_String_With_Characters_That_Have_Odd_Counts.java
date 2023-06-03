class Solution {
    public String generateTheString(int n) {
        if (n == 1) {
            return "a";
        }

        StringBuilder answer = new StringBuilder();

        if (n % 2 == 0) {
            for (int i = 0; i < n - 1; i++) {
                answer.append('a');
            }

            answer.append('b');
        } else {
            for (int i = 0; i < n - 2; i++) {
                answer.append('a');
            }

            answer.append('b');
            answer.append('c');
        }

        return answer.toString();
    }
}