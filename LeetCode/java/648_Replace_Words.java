import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {
    public String replaceWords(List<String> dictionary, String sentence) {
        StringBuilder answer = new StringBuilder();

        Set<String> set = new HashSet<>();

        for (String s : dictionary) {
            set.add(s);
        }

        String[] arr = sentence.split(" ");

        for (String s : arr) {
            StringBuilder sb = new StringBuilder();
            boolean flag = false;

            for (int i = 0; i < s.length(); i++) {
                sb.append(s.charAt(i));

                if (set.contains(sb.toString())) {
                    answer.append(sb.toString());
                    answer.append(" ");
                    flag = true;
                    break;
                }
            }

            if (!flag) {
                answer.append(sb.toString());
                answer.append(" ");
            }
        }

        answer.deleteCharAt(answer.length() - 1);

        return answer.toString();
    }
}