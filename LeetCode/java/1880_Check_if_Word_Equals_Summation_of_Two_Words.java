import java.util.ArrayList;
import java.util.List;

class Solution {
    public boolean isSumEqual(String firstWord, String secondWord, String targetWord) {
        List<Character> alphabet = new ArrayList<>();

        for (int i = 0; i < 26; i++) {
            alphabet.add((char)('0' + i));
        }

        StringBuilder first = new StringBuilder(firstWord);
        StringBuilder second = new StringBuilder(secondWord);
        StringBuilder target = new StringBuilder(targetWord);

        for (int i = 0; i < first.length(); i++) {
            first.setCharAt(i, alphabet.get(first.charAt(i) - 'a'));
        }

        for (int i = 0; i < second.length(); i++) {
            second.setCharAt(i, alphabet.get(second.charAt(i) - 'a'));
        }

        for (int i = 0; i < target.length(); i++) {
            target.setCharAt(i, alphabet.get(target.charAt(i) - 'a'));
        }

        long firstNumber = Long.parseLong(first.toString());
        long secondNumber = Long.parseLong(second.toString());

        long sum = firstNumber + secondNumber;

        if (sum == Long.parseLong(target.toString())) {
            return true;
        }

        return false;
    }
}