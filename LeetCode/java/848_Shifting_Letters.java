class Solution {
    public String shiftingLetters(String s, int[] shifts) {
        int[] culSum = new int[shifts.length];
        culSum[culSum.length - 1] = shifts[shifts.length - 1];

        for (int i = shifts.length - 2; i >= 0; i--) {
            culSum[i] = (shifts[i] + culSum[i + 1]) % 26;
        }

        StringBuilder sb = new StringBuilder(s);

        for (int i = 0; i < sb.length(); i++) {
            int n = sb.charAt(i) + (culSum[i] % 26);

            if (n > 122) {
                n -= 26;
            }

            sb.setCharAt(i, (char)n);
        }

        return sb.toString();
    }
}