import java.util.*;

class Solution {
    public String solution(String s, String skip, int index) {
        String answer = "";

        Set<Character> set = new HashSet<>();

        for (int i = 0; i < skip.length(); i++) {
            set.add(skip.charAt(i));
        }

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            for (int j = 0; j < index; j++) {
                c = (char)(c + 1);

                if (c > 'z') {
                    c = 'a';
                }

                if (set.contains(c)) {
                    j--;
                }
            }

            answer += String.valueOf(c);
        }

        return answer;
    }
}