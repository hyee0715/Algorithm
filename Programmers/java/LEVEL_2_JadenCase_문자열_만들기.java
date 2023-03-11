class Solution {
    public String solution(String s) {
        String answer = "";

        StringBuilder sb = new StringBuilder(s);

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                continue;
            }

            if (i == 0 || s.charAt(i - 1) == ' ') {
                String str = String.valueOf(s.charAt(i));
                str = str.toUpperCase();
                char c = str.charAt(0);
                sb.setCharAt(i, c);
                continue;
            }

            String str = String.valueOf(s.charAt(i));
            str = str.toLowerCase();
            char c = str.charAt(0);
            sb.setCharAt(i, c);
        }

        answer = sb.toString();

        return answer;
    }
}