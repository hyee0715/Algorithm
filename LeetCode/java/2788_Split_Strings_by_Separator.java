import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<String> splitWordsBySeparator(List<String> words, char separator) {
        List<String> answer = new ArrayList<>();

        StringBuilder sb = new StringBuilder();
        for (String word : words) {
            for (int i = 0; i < word.length(); i++) {
                if (word.charAt(i) == separator) {
                    if (!sb.isEmpty()) {
                        answer.add(sb.toString());
                        sb.setLength(0);
                    }
                } else {
                    sb.append(word.charAt(i));
                }
            }

            if (!sb.isEmpty()) {
                answer.add(sb.toString());
                sb.setLength(0);
            }
        }

        return answer;
    }
}