import java.util.*;

class Solution {
    public int solution(String dartResult) {
        int answer = 0;
        List<Integer> number = new ArrayList<>();
        List<Character> type = new ArrayList<>();
        String[] option = new String[3];

        Arrays.fill(option, "");

        String s = "";
        int timeCount = -1;
        for (int i = 0; i < dartResult.length(); i++) {
            if (dartResult.charAt(i) == 'S' || dartResult.charAt(i) == 'D' || dartResult.charAt(i) == 'T') {
                timeCount++; //몇 번째 기회인지 구분

                int n = Integer.parseInt(s);
                number.add(n);
                s = "";

                type.add(dartResult.charAt(i));

                continue;
            }

            if (dartResult.charAt(i) == '*') {
                if (timeCount == 0) {
                    option[timeCount] += '*';
                } else if (timeCount > 0) {
                    option[timeCount - 1] += '*';
                    option[timeCount] += '*';
                }

                continue;
            }

            if (dartResult.charAt(i) == '#') {
                option[timeCount] += '#';

                continue;
            }

            s += dartResult.charAt(i);
        }

        for (int i = 0; i < 3; i++) {
            int score = number.get(i);

            if (type.get(i) == 'D') {
                score = score * score;
            } else if (type.get(i) == 'T') {
                score = score * score * score;
            }

            for (int j = 0; j < option[i].length(); j++) {
                if (option[i].charAt(j) == '*') {
                    score *= 2;
                    continue;
                }

                //'#'인 경우
                score *= -1;
            }

            answer += score;
        }

        return answer;
    }
}