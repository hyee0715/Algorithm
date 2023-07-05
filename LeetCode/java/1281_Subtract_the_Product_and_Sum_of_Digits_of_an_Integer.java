class Solution {
    public int subtractProductAndSum(int n) {
        int answer = 0;

        String s = String.valueOf(n);

        int product = 1;
        int sum = 0;

        for (int i = 0; i < s.length(); i++) {
            product *= (s.charAt(i) - '0');
            sum += (s.charAt(i) - '0');
        }

        answer = product - sum;
        return answer;
    }
}