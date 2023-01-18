import java.util.*;

class Solution {
    public int shortestWordDistance(String[] wordsDict, String word1, String word2) {
        int answer = 100002;
        Map<String, List<Integer>> map = new HashMap<>();

        for (int i = 0; i < wordsDict.length; i++) {
            if (!map.containsKey(wordsDict[i])) {
                map.put(wordsDict[i], new ArrayList<>());
            }

            map.get(wordsDict[i]).add(i);
        }

        if (word1.equals(word2)) {
            List<Integer> list = map.get(word1);

            Collections.sort(list);

            for (int i = 0; i < list.size() - 1; i++) {
                answer = Math.min(answer, list.get(i + 1) - list.get(i));
            }

            return answer;
        }

        List<Integer> list1 = map.get(word1);
        List<Integer> list2 = map.get(word2);

        Collections.sort(list1);
        Collections.sort(list2);

        int p1 = 0;
        int p2 = 0;

        while (p1 < list1.size() && p2 < list2.size()) {
            answer = Math.min(answer, Math.abs(list1.get(p1) - list2.get(p2)));

            if (list1.get(p1) <= list2.get(p2)) {
                p1++;
                continue;
            }

            if (list1.get(p1) > list2.get(p2)) {
                p2++;
            }
        }

        return answer;
    }
}