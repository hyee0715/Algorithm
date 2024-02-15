class Solution {
    public String solution(String s) {
        String answer = "";

        String[] words = s.split(" ", -1);

        for (int i = 0; i < words.length; i++) {
            StringBuilder sb = new StringBuilder();

            for (int j = 0; j < words[i].length(); j++) {
                if (j % 2 == 0) {
                    sb.append(String.valueOf(words[i].charAt(j)).toUpperCase());
                } else {
                    sb.append(String.valueOf(words[i].charAt(j)).toLowerCase());
                }
            }

            answer += sb.toString();

            if (i != words.length - 1) {
                answer += " ";
            }
        }

        return answer;
    }
}