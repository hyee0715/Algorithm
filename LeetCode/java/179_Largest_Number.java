import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

class Solution {
    boolean allZero(int[] nums) {
        for (int num : nums) {
            if (num != 0) {
                return false;
            }
        }

        return true;
    }

    public String largestNumber(int[] nums) {
        if (allZero(nums)) {
            return "0";
        }

        List<String> list = new ArrayList<>();
        StringBuilder answer = new StringBuilder();

        for (int num : nums) {
            list.add(String.valueOf(num));
        }

        Collections.sort(list, new Comparator<String>() {
            public int compare(String a, String b) {
                String order1 = a + b;
                String order2 = b + a;
                return order2.compareTo(order1);
            }
        });

        for (String s : list) {
            answer.append(s);
        }

        return answer.toString();
    }
}