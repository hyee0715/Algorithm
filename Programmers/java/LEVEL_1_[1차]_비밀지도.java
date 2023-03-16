import java.util.*;

class Solution {
    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = new String[n];

        List<String> map1 = new ArrayList<>();
        List<String> map2 = new ArrayList<>();

        for (int i = 0; i < arr1.length; i++) {
            map1.add(makeBinary(n, arr1[i]));
        }

        for (int i = 0; i < arr2.length; i++) {
            map2.add(makeBinary(n, arr2[i]));
        }

        for (int i = 0; i < n; i++) {
            String s = "";

            for (int j = 0; j < n; j++) {
                if (map1.get(i).charAt(j) == '1' || map2.get(i).charAt(j) == '1') {
                    s += '#';
                    continue;
                }

                s += ' ';
            }

            answer[i] = s;
        }

        return answer;
    }

    private String makeBinary(int limitLength, int n) {
        StringBuilder sb = new StringBuilder();

        while (n > 0) {
            if (n % 2 == 0) {
                sb.append('0');
            } else {
                sb.append('1');
            }

            n /= 2;
        }

        sb = sb.reverse();

        String s = sb.toString();
        while (s.length() < limitLength) {
            s = '0' + s;
        }

        return s;
    }
}