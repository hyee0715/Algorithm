import java.util.*;

class Solution {
    public int[] solution(String[] name, int[] yearning, String[][] photo) {
        int[] answer = new int[photo.length];
        int idx = 0;

        Map<String, Integer> map = new HashMap<>();

        for (int i = 0; i < name.length; i++) {
            map.put(name[i], yearning[i]);
        }

        for (String[] p : photo) {
            int num = 0;

            for (String n : p) {
                if (map.containsKey(n)) {
                    num += map.get(n);
                }
            }

            answer[idx++] = num;
        }

        return answer;
    }
}