import java.util.ArrayList;
import java.util.List;

class Solution {
    public String reverseWords(String s) {
        List<String> list = new ArrayList<>();
        StringBuilder sb = new StringBuilder(s);

        while (true) {
            if (sb.charAt(0) == ' ') {
                sb.delete(0, 1);
            } else {
                break;
            }
        }

        while (true) {
            if (sb.charAt(sb.length() - 1) == ' ') {
                sb.delete(sb.length() - 1, sb.length());
            } else {
                break;
            }
        }

        s = sb.toString();

        sb.setLength(0);

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' ') {
                if (sb.length() > 0) {
                    list.add(sb.toString());
                    sb.setLength(0);
                }
            } else {
                sb.append(s.charAt(i));
            }
        }

        if (sb.length() > 0) {
            list.add(sb.toString());
            sb.setLength(0);
        }

        for (int i = list.size() - 1; i >= 0; i--) {
            sb.append(list.get(i));

            if (i != 0)
                sb.append(" ");
        }

        return sb.toString();
    }
}