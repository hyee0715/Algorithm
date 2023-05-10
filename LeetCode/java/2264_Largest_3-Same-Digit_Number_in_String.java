import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class Solution {
    public String largestGoodInteger(String num) {
        String answer = "";
        List<String> goodIntegers = new ArrayList<>();

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 3; i++) {
            sb.append(num.charAt(i));
        }

        if (sb.charAt(0) == sb.charAt(1) && sb.charAt(1) == sb.charAt(2)) {
            goodIntegers.add(sb.toString());
        }

        for (int i = 3; i < num.length(); i++) {
            sb.deleteCharAt(0);
            sb.append(num.charAt(i));

            if (sb.charAt(0) == sb.charAt(1) && sb.charAt(1) == sb.charAt(2)) {
                goodIntegers.add(sb.toString());
            }
        }

        if (goodIntegers.size() > 0) {
            Collections.sort(goodIntegers);
            answer = goodIntegers.get(goodIntegers.size() - 1);
        }

        return answer;
    }
}