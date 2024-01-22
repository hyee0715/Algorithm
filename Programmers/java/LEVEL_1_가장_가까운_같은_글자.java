import java.util.*;

class Solution {
    public int[] solution(String s) {
        int[] answer = new int[s.length()];
        Map<Character, List<Integer>> map = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            if (map.containsKey(s.charAt(i))) {
                List<Integer> list = map.get(s.charAt(i));
                int num = list.get(list.size() - 1);

                answer[i] = i - num;
                list.add(i);
            } else {
                answer[i] = -1;

                map.put(s.charAt(i), new ArrayList<>());
                List<Integer> list = map.get(s.charAt(i));
                list.add(i);
            }
        }

        return answer;
    }
}