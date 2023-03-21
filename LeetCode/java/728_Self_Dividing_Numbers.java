import java.util.ArrayList;
import java.util.List;

class Solution {
    private boolean check(int num, String str) {
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == '0') {
                return false;
            }

            int n = str.charAt(i) - '0';
            if (num % n != 0) {
                return false;
            }
        }

        return true;
    }

    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> answer = new ArrayList<>();

        for (int i = left; i <= right; i++) {
            String num = String.valueOf(i);

            if (check(i, num)) {
                answer.add(i);
            }
        }

        return answer;
    }
}