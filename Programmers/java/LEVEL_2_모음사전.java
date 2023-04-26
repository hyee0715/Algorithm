import java.util.*;

class Solution {
    private void dfs(char ch[], int cnt, String word, StringBuilder s, List<String> list) {
        if (cnt == 5) {
            return;
        } else {
            for (int i = 0; i < 5; i++) {
                s.append(ch[i]);
                list.add(s.toString());
                dfs(ch, cnt + 1, word, s, list);
                s.deleteCharAt(s.length() - 1);
            }
        }
    }

    public int solution(String word) {
        int answer = 0;

        char[] ch = new char[] {'A', 'E', 'I', 'O', 'U'};

        StringBuilder s = new StringBuilder();
        List<String> list = new ArrayList<>();
        dfs(ch, 0, word, s, list);

        for (int i = 0; i < list.size(); i++) {
            if (list.get(i).equals(word)) {
                answer = i + 1;
                break;
            }
        }

        return answer;
    }
}