import java.util.*;

class Solution {
    List<Integer> idxs = new ArrayList<>();
    List<Integer> list = new ArrayList<>();
    boolean[] visit;
    Map<Character, String> map1 = new HashMap<>();
    Map<String, Character> map2 = new HashMap<>();
    Set<String> st = new HashSet<>();
    boolean answerFlag = false;

    public boolean wordPatternMatch(String pattern, String s) {
        for (int i = 0; i < s.length(); i++) {
            idxs.add(i);
        }

        visit = new boolean[idxs.size()];
        answerFlag = false;

        //조합, pattern.length()만큼 뽑기
        dfs(0, 0, pattern, s);

        return answerFlag;
    }

    private void dfs(int idx, int cnt, String pattern, String s) {
        if (cnt == pattern.length()) {
            map1.clear();
            map2.clear();

            if (check(pattern, s)) {
                answerFlag = true;
            }

            return;
        }

        for (int i = idx; i < idxs.size(); i++) {
            if (visit[i] == true) {
                continue;
            }

            visit[i] = true;
            list.add(idxs.get(i));
            dfs(i, cnt + 1, pattern, s);
            list.remove(list.size() - 1);
            visit[i] = false;
        }
    }

    private boolean check(String pattern, String s) {
        List<String> words = splitWords(s);;

        for (int i = 0; i < pattern.length(); i++) {
            if (!map1.containsKey(pattern.charAt(i))) {
                if (!map2.containsKey(words.get(i))) {
                    map1.put(pattern.charAt(i), words.get(i));
                    map2.put(words.get(i), pattern.charAt(i));
                } else {
                    return false;
                }
            } else {
                String mapWord = map1.get(pattern.charAt(i));

                if (!mapWord.equals(words.get(i))) {
                    return false;
                }
            }
        }

        return true;
    }

    private List<String> splitWords(String s) {
        List<String> ret = new ArrayList<>();

        String temp = s.substring(0, list.get(0) + 1);
        ret.add(temp);

        for (int i = 1; i < list.size() - 1; i++) {
            temp = s.substring(list.get(i), list.get(i + 1));
            ret.add(temp);
        }

        temp = s.substring(list.get(list.size() - 1), s.length());
        ret.add(temp);

        return ret;
    }
}