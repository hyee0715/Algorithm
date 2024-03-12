class Solution {
    public int countKeyChanges(String s) {
        int answer = 0;

        s = s.toUpperCase();

        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) != s.charAt(i + 1)) {
                answer++;
            }
        }

        return answer;
    }
}