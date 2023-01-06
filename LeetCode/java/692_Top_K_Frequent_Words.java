import java.util.*;

class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> unorderedMap = new HashMap<>();
        Map<Integer, List<String>> map = new TreeMap<>(Collections.reverseOrder());
        List<String> answer = new ArrayList<>();
        boolean flag = false;

        for (int i = 0; i < words.length; i++) {
            unorderedMap.put(words[i], unorderedMap.getOrDefault(words[i], 0) + 1);
        }

        for (String key : unorderedMap.keySet()) {
            if (!map.containsKey(unorderedMap.get(key))) {
                map.put(unorderedMap.get(key), new ArrayList<>());
            }

            map.get(unorderedMap.get(key)).add(key);
        }

        for (int key : map.keySet()) {
            List<String> list = map.get(key);

            for (int i = 0; i < list.size(); i++) {
                Collections.sort(list);
                answer.add(list.get(i));
                k--;

                if (k == 0) {
                    flag = true;
                    break;
                }
            }

            if (flag) {
                break;
            }
        }

        return answer;
    }
}