import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class WordDistance {
    Map<String, List<Integer>> map = new HashMap<>();

    public WordDistance(String[] wordsDict) {
        for (int i = 0; i < wordsDict.length; i++) {
            if (!map.containsKey(wordsDict[i])) {
                map.put(wordsDict[i], new ArrayList<Integer>());
            }

            map.get(wordsDict[i]).add(i);
        }
    }

    public int shortest(String word1, String word2) {
        List<Integer> n1 = map.get(word1);
        List<Integer> n2 = map.get(word2);

        int answer = 300002;
        for (int i = 0; i < n1.size(); i++) {
            for (int j = 0; j < n2.size(); j++) {
                answer = Math.min(answer, Math.abs(n1.get(i) - n2.get(j)));
            }
        }

        return answer;
    }
}

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(wordsDict);
 * int param_1 = obj.shortest(word1,word2);
 */