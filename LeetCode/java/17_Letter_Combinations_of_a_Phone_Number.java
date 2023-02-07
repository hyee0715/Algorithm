import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> answer = new ArrayList<>();
        Map<Character, String> phone = new HashMap<>();

        phone.put('2', "abc");
        phone.put('3', "def");
        phone.put('4', "ghi");
        phone.put('5', "jkl");
        phone.put('6', "mno");
        phone.put('7', "pqrs");
        phone.put('8', "tuv");
        phone.put('9', "wxyz");

        for (int i = 0; i < digits.length(); i++) {
            String s = phone.get(digits.charAt(i));

            if (answer.isEmpty() && i == 0) {
                for (int j = 0; j < s.length(); j++) {
                    StringBuilder sb = new StringBuilder();
                    sb.append(s.charAt(j));
                    answer.add(sb.toString());
                }

                continue;
            }

            List<String> temp = new ArrayList<>();
            int size = answer.size();

            for (String t : answer) {
                temp.add(t);
            }

            answer = new ArrayList<>();

            for (int j = 0; j < size; j++) {
                String str = temp.get(temp.size() - 1);
                temp.remove(temp.size() - 1);

                for (int k = 0; k < s.length(); k++) {
                    answer.add(str + s.charAt(k));
                }
            }
        }

        return answer;
    }
}