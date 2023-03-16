class Solution {
    public int[] solution(long n) {
        int[] answer = {};

        String s = String.valueOf(n);
        StringBuilder sb = new StringBuilder(s);

        s = sb.reverse().toString();

        answer = new int[s.length()];

        for (int i = 0; i < s.length(); i++) {
            answer[i] = s.charAt(i) - '0';
        }

        return answer;
    }
}