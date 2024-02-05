import java.util.*;

class Solution {
    private int findMaxStrIdx(int cur, String msg, Map<String, Integer> dic) {
        String s = String.valueOf(msg.charAt(cur));

        for (int i = cur + 1; i < msg.length(); i++) {
            if (!dic.containsKey(s + msg.charAt(i))) {
                return i - 1;
            } else {
                s = s + String.valueOf(msg.charAt(i));
            }
        }

        return msg.length() - 1;
    }

    public int[] solution(String msg) {
        int[] answer = {};
        List<Integer> tempAns = new ArrayList<>();
        Map<String, Integer> dictionary = new HashMap<>();

        int idx = 0;
        char c = 'A';
        while (idx <= 25) {
            dictionary.put(String.valueOf((char)(c + idx)), idx + 1);
            idx++;
        }

        for (int i = 0; i < msg.length(); i++) {
            int endIdx = findMaxStrIdx(i, msg, dictionary); //가능한 문자열 마지막 인덱스 위치 구하기

            StringBuilder sb = new StringBuilder();
            for (int j = i; j <= endIdx; j++) {
                sb.append(msg.charAt(j));
            }

            i = endIdx;

            String str = sb.toString();

            if (dictionary.containsKey(str)) {
                tempAns.add(dictionary.get(str));
            }

            if (i < msg.length() - 1) {
                dictionary.put(str + String.valueOf(msg.charAt(i + 1)), ++idx);
            }
        }

        answer = new int[tempAns.size()];
        int ansIdx = 0;

        for (int ans : tempAns) {
            answer[ansIdx++] = ans;
        }

        return answer;
    }
}