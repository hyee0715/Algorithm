import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public int numMatchingSubseq(String s, String[] words) {
        Map<Character, List<String>> map = new HashMap<>();
        int answer = 0;

        for (int i = 0; i < words.length; i++) {
            if (!map.containsKey(words[i].charAt(0))) {
                map.put(words[i].charAt(0), new ArrayList<>());
            }

            map.get(words[i].charAt(0)).add(words[i]);
        }

        for (int i = 0; i < s.length(); i++) {
            if (!map.containsKey(s.charAt(i))) {
                continue;
            }

            List<String> wordList = map.get(s.charAt(i));
            map.remove(s.charAt(i));

            for (int j = 0; j < wordList.size(); j++) {
                String word = wordList.get(j);

                word = word.substring(1, word.length());

                if (word.length() == 0) {
                    answer++;
                    continue;
                }

                if (!map.containsKey(word.charAt(0))) {
                    map.put(word.charAt(0), new ArrayList<>());
                }

                map.get(word.charAt(0)).add(word);
            }
        }

        return answer;
    }
}