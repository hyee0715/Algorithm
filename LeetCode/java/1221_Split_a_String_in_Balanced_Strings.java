class Solution {
    public int balancedStringSplit(String s) {
        int answer = 0;

        int r = 0, l = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'R') {
                r++;
            } else {
                l++;
            }

            if (r == l) {
                answer++;
                r = 0;
                l = 0;
            }
        }

        return answer;
    }
}