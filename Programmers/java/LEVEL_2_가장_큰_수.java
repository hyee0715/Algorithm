import java.util.*;

class Solution {
    private boolean allZeroCheck(int[] numbers) {
        for (int n : numbers) {
            if (n != 0) {
                return false;
            }
        }

        return true;
    }

    public String solution(int[] numbers) {
        String answer = "";

        if (allZeroCheck(numbers)) {
            return "0";
        }

        List<String> list = new ArrayList<>();

        for (int i = 0; i < numbers.length; i++) {
            list.add(String.valueOf(numbers[i]));
        }

        Collections.sort(list, (x, y) -> {
            if ((x + y).compareTo(y + x) < 0) {
                return 1;
            }

            if ((x + y).compareTo(y + x) > 0) {
                return -1;
            }

            return 0;
        });

        for (String s : list) {
            answer += s;
        }

        return answer;
    }
}