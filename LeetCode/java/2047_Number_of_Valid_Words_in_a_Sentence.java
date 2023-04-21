import java.util.ArrayList;
import java.util.List;

class Solution {
    public int countValidWords(String sentence) {
        int answer = 0;
        String[] splited = sentence.split(" ");
        List<String> words = new ArrayList<>();

        for (String s : splited) {
            if (s.length() != 0) {
                words.add(s);
            }
        }

        for (String word : words) {
            boolean hyphen = false;
            boolean punctuationMark = false;

            boolean valid = true;
            for (int i = 0; i < word.length(); i++) {
                if (word.charAt(i) >= '0' && word.charAt(i) <= '9') {
                    valid = false;
                    break;
                }

                if (word.charAt(i) == '-') {
                    if (i == 0 || i == word.length() - 1 || hyphen) {
                        valid = false;
                        break;
                    }

                    if (word.charAt(i - 1) == '.' || word.charAt(i - 1) == ',' || word.charAt(i - 1) == '!' || word.charAt(i - 1) == '-' || word.charAt(i + 1) == '.' || word.charAt(i + 1) == ',' || word.charAt(i + 1) == '!' || word.charAt(i + 1) == '-') {
                        valid = false;
                        break;
                    }

                    hyphen = true;
                }

                if (word.charAt(i) == '.' || word.charAt(i) == ',' || word.charAt(i) == '!') {
                    if (punctuationMark || i != word.length() - 1) {
                        valid = false;
                        break;
                    }

                    punctuationMark = true;
                }
            }

            if (valid) {
                answer++;
            }
        }

        return answer;
    }
}