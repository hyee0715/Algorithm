import java.util.ArrayList;
import java.util.List;

class Solution {
    public int maxProduct(String[] words) {
        List<Integer> nums = new ArrayList<>();
        List<Integer> wordsLength = new ArrayList<>();
        int answer = -1;

        for (int i = 0; i < words.length; i++) {
            String s = words[i];

            int n = 0;
            for (int j = 0; j < s.length(); j++) {
                n |= (1 << (s.charAt(j) - 'a'));
            }

            nums.add(n);
            wordsLength.add(words[i].length());
        }

        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if ((nums.get(i) & nums.get(j)) == 0) {
                    answer = Math.max(answer, wordsLength.get(i) * wordsLength.get(j));
                }
            }
        }

        if (answer == -1) {
            answer = 0;
        }

        return answer;
    }
}