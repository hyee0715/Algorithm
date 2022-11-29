import java.util.ArrayList;
import java.util.List;

class Solution {
    public int countSegments(String s) {
        List<String> list = new ArrayList<>();

        StringBuilder temp = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' ') {
                if (temp.length() == 0) {
                    continue;
                }

                list.add(temp.toString());
                temp.setLength(0);
            }
            else {
                temp.append(s.charAt(i));
            }
        }

        if (temp.length() != 0) {
            list.add(temp.toString());
        }

        return list.size();
    }
}