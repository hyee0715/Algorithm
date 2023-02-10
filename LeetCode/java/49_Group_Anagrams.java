import java.util.*;

class Solution {
    private String makeString(Map<Character, Integer> orderMap) {
        StringBuilder sb = new StringBuilder();

        for (char key : orderMap.keySet()) {
            while (orderMap.get(key) > 0) {
                sb.append(key);
                orderMap.put(key, orderMap.get(key) - 1);
            }
        }

        return sb.toString();
    }

    public List<List<String>> groupAnagrams(String[] strs) {
        List<List<String>> answer = new ArrayList<>();
        Map<String, List<String>> map = new HashMap<>();

        for (int i = 0; i < strs.length; i++) {
            Map<Character, Integer> orderMap = new TreeMap<>();

            for (int j = 0; j < strs[i].length(); j++) {
                orderMap.put(strs[i].charAt(j), orderMap.getOrDefault(strs[i].charAt(j), 0) + 1);
            }

            String s = makeString(orderMap);

            if (!map.containsKey(s)) {
                map.put(s, new ArrayList<>());
            }

            map.get(s).add(strs[i]);
        }

        for (String key : map.keySet()) {
            answer.add(map.get(key));
        }

        return answer;
    }
}