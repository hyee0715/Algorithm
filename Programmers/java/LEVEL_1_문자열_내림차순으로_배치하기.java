import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";

        StringBuilder a = new StringBuilder();
        StringBuilder b = new StringBuilder();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) >= 'A' && s.charAt(i) <= 'Z') {
                b.append(s.charAt(i));
            } else {
                a.append(s.charAt(i));
            }
        }

        char[] aArr = a.toString().toCharArray();
        char[] bArr = b.toString().toCharArray();

        Arrays.sort(aArr);
        Arrays.sort(bArr);

        a.setLength(0);
        b.setLength(0);

        for (char c : aArr) {
            a.append(c);
        }

        for (char c : bArr) {
            b.append(c);
        }

        a.reverse();
        b.reverse();

        answer = a.toString() + b.toString();

        return answer;
    }
}