import java.util.*;

class Solution {
    public int[] solution(int n, String[] words) {
        int[] answer = new int[] {0, 0};
        Set<String> dup = new HashSet<>();

        char startChar = words[0].charAt(0);

        int cnt = 0;
        int idx = 0;

        for (String word : words) {
            if (word.charAt(0) != startChar || dup.contains(word)) {
                answer = new int[] {idx + 1, cnt + 1};
                break;
            }

            dup.add(word);
            startChar = word.charAt(word.length() - 1);

            idx++;

            if (idx == n) {
                idx = 0;
                cnt++;
            }
        }

        return answer;
    }
}