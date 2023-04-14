import java.util.*;

class Solution {
    public int[] solution(String s) {
        int[] answer = {};
        Map<Integer, Integer> map = new HashMap<>();

        List<String> extract1 = new ArrayList<>();
        List<String> extract2 = new ArrayList<>();
        List<List<Integer>> extract3 = new ArrayList<>();

        //가장 바깥 {} 없애기
        StringBuilder temp = new StringBuilder();
        for (int i = 1; i < s.length() - 1; i++) {
            if (s.charAt(i) == ',' && s.charAt(i - 1) == '}' && s.charAt(i + 1) == '{') {
                extract1.add(temp.toString());
                temp.setLength(0);
                continue;
            }

            temp.append(s.charAt(i));
        }

        extract1.add(temp.toString());
        temp.setLength(0);

        //각 튜플의 {} 없애기
        for (String ex : extract1) {
            for (int i = 1; i < ex.length() - 1; i++) {
                temp.append(ex.charAt(i));
            }

            extract2.add(temp.toString());
            temp.setLength(0);
        }

        //각 튜플의 숫자 추출
        for (String ext : extract2) {
            List<Integer> list = new ArrayList<>();

            String[] spl = ext.split(",");
            for (String str : spl) {
                list.add(Integer.parseInt(str));
            }

            List<Integer> copy = new ArrayList<>(list);
            extract3.add(copy);
            list.clear();
        }

        for (List<Integer> e : extract3) {
            for (int i = 0; i < e.size(); i++) {
                map.put(e.get(i), map.getOrDefault(e.get(i), 0) + 1);
            }
        }

        List<int[]> count = new ArrayList<>(); //숫자 카운트, 수
        for (int key : map.keySet()) {
            count.add(new int[]{map.get(key), key});
        }

        Collections.sort(count, (x, y) -> {
            if (x[0] < y[0]) {
                return 1;
            }

            if (x[0] > y[0]) {
                return -1;
            }

            return 0;
        });

        answer = new int[count.size()];
        int idx = 0;

        for (int i = 0; i < count.size(); i++) {
            int[] cur = count.get(i);
            answer[idx++] = cur[1];
        }

        return answer;
    }
}