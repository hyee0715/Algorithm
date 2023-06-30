import java.util.ArrayList;
import java.util.List;

class Solution {
    private List<String> extract(String s) {
        List<String> list = new ArrayList<>();

        StringBuilder temp = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '|') {
                list.add(temp.toString());
                temp.setLength(0);
            } else {
                temp.append(s.charAt(i));
            }
        }

        if (temp.length() != 0) {
            list.add(temp.toString());
        }

        return list;
    }

    public int countAsterisks(String s) {
        int answer = 0;
        List<String> words = extract(s);

        for (int i = 0; i < words.size(); i++) {
            if (i % 2 != 0) {
                continue;
            }

            for (int j = 0; j < words.get(i).length(); j++) {
                if (words.get(i).charAt(j) == '*') {
                    answer++;
                }
            }
        }

        return answer;
    }
}