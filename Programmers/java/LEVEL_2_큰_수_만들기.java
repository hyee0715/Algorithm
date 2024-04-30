import java.util.*;

class Solution {
    public String solution(String number, int k) {
        String answer = "";
        List<Character> list = new ArrayList<>();
        int removeCount = 0;

        int idx = 0;
        for (; idx < number.length(); idx++) {
            if (removeCount == k) {
                break;
            }

            char c = number.charAt(idx);

            if (list.isEmpty()) {
                list.add(c);
            } else {
                while (!list.isEmpty() || removeCount == k) {
                    if (list.get(list.size() - 1) < c) {
                        list.remove(list.size() - 1);
                        removeCount++;

                        if (removeCount == k) {
                            break;
                        }
                    } else {
                        break;
                    }
                }

                list.add(c);
            }
        }

        if (list.size() >= number.length() - k) {
            for (int i = 0; i < number.length() - k; i++) {
                answer += list.get(i);
            }
        } else {
            for (int i = 0; i < list.size(); i++) {
                answer += list.get(i);
            }

            while (idx < number.length()) {
                answer += number.charAt(idx++);
            }
        }

        return answer;
    }
}