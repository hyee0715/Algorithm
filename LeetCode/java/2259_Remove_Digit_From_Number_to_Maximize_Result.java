import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    public String removeDigit(String number, char digit) {
        String answer = "";
        List<Integer> idx = new ArrayList<>();
        List<String> list = new ArrayList<>();

        for (int i = 0; i < number.length(); i++) {
            if (number.charAt(i) == digit) {
                idx.add(i);
            }
        }

        for (int i : idx) {
            StringBuilder temp = new StringBuilder(number);

            temp.deleteCharAt(i);
            list.add(temp.toString());
        }

        Collections.sort(list);

        answer = list.get(list.size() - 1);

        return answer;
    }
}