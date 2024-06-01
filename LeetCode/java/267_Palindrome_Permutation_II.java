import java.util.*;

class Solution {
    Map<Character, Integer> map = new HashMap<>();
    List<Character> chars = new ArrayList<>();
    List<Character> list = new ArrayList<>();
    boolean[] visit;
    Set<String> st = new HashSet<>();

    public List<String> generatePalindromes(String s) {
        List<String> answer = new ArrayList<>();

        for (int i = 0; i < s.length(); i++) {
            map.put(s.charAt(i), map.getOrDefault(s.charAt(i), 0) + 1);
        }

        if (!validateMap()) {
            return answer;
        }

        char oddCntChar = '*';
        for (char key : map.keySet()) {
            if (map.get(key) % 2 != 0) {
                oddCntChar = key;
            }

            for (int i = 0; i < map.get(key) / 2; i++) {
                chars.add(key);
            }
        }

        visit = new boolean[chars.size()];

        dfs(0, s, oddCntChar);

        for (String ss : st) {
            answer.add(ss);
        }

        return answer;
    }

    private void dfs(int cnt, String s, char oddChar) {
        if (cnt == chars.size()) {
            StringBuilder temp = new StringBuilder();
            StringBuilder result = new StringBuilder();

            for (int i = 0; i < list.size(); i++) {
                temp.append(list.get(i));
            }

            StringBuilder rev = new StringBuilder(temp.toString());
            rev.reverse();

            if (oddChar == '*') {
                result.append(temp.toString());
                result.append(rev.toString());
            } else {
                result.append(temp.toString());
                result.append(oddChar);
                result.append(rev.toString());
            }

            st.add(result.toString());

            return;
        }

        for (int i = 0; i < chars.size(); i++) {
            if (visit[i] == true) {
                continue;
            }

            visit[i] = true;
            list.add(chars.get(i));
            dfs(cnt + 1, s, oddChar);
            list.remove(list.size() - 1);
            visit[i] = false;
        }
    }

    private boolean validateMap() {
        boolean flag = false;

        for (char key : map.keySet()) {
            if (map.get(key) % 2 != 0) {
                if (!flag) {
                    flag = true;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
}