import java.util.*;

class Solution {
    public String solution(String X, String Y) {
        String answer = "";

        Map<Integer, Integer> map1 = new HashMap<>();
        Map<Integer, Integer> map2 = new HashMap<>();
        List<Integer> list = new ArrayList<>();

        for (int i = 0; i < X.length(); i++) {
            map1.put(X.charAt(i) - '0', map1.getOrDefault(X.charAt(i) - '0', 0) + 1);
        }

        for (int i = 0; i < Y.length(); i++) {
            map2.put(Y.charAt(i) - '0', map2.getOrDefault(Y.charAt(i) - '0', 0) + 1);
        }

        for (int key : map1.keySet()) {
            int num = key;
            int cnt = -1;

            if (map2.containsKey(num)) {
                cnt = Math.min(map1.get(num), map2.get(num));
            }

            for (int i = 0; i < cnt; i++) {
                list.add(num);
            }
        }

        if (list.isEmpty()) {
            answer = "-1";
            return answer;
        }

        Collections.sort(list, Collections.reverseOrder());

        if (list.size() > 1 && list.get(0) == 0) {
            answer = "0";
            return answer;
        }

        StringBuilder sb = new StringBuilder();
        for (int n : list) {
            sb.append(String.valueOf(n));
        }

        answer = sb.toString();
        return answer;
    }
}