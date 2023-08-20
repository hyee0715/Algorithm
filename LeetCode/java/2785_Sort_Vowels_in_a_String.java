import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    public String sortVowels(String s) {
        StringBuilder sb = new StringBuilder(s);
        List<Character> list = new ArrayList<>();

        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s.charAt(i))) {
                list.add(s.charAt(i));
            }
        }

        Collections.sort(list);

        int idx = 0;

        for (int i = 0; i < s.length(); i++) {
            if (isVowel(s.charAt(i))) {
                sb.setCharAt(i, list.get(idx++));
            }
        }

        return sb.toString();
    }

    boolean isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'u' || c == 'o' || c == 'A' || c == 'E' || c == 'I' || c == 'U' || c == 'O') {
            return true;
        }

        return false;
    }
}