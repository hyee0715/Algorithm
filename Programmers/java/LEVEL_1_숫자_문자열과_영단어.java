import java.util.*;

class Solution {
    public int solution(String s) {
        int answer = 0;
        StringBuilder strAnswer = new StringBuilder();
        Map<String, Character> map = new HashMap<>();

        String[] numbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

        for (int i = 0; i < 10; i++) {
            map.put(numbers[i], (char)(i + '0'));
        }

        StringBuilder temp = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                if (temp.length() != 0) {
                    strAnswer.append(map.get(temp.toString()));
                    temp.setLength(0);
                }

                strAnswer.append(s.charAt(i));
                continue;
            }

            temp.append(s.charAt(i));

            if (map.containsKey(temp.toString())) {
                strAnswer.append(map.get(temp.toString()));
                temp.setLength(0);
            }
        }

        if (temp.length() != 0) {
            strAnswer.append(map.get(temp.toString()));
            temp.setLength(0);
        }

        answer = Integer.parseInt(strAnswer.toString());

        return answer;
    }
}