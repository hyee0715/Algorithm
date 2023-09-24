import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";

        String[] nums = s.split(" ");

        List<Integer> list = new ArrayList<>();
        for (String num : nums) {
            list.add(Integer.parseInt(num));
        }

        Collections.sort(list);

        answer = String.valueOf(list.get(0)) + ' ' + String.valueOf(list.get(list.size() - 1));

        return answer;
    }
}