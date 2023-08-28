import java.util.List;

class Solution {
    public boolean isAcronym(List<String> words, String s) {
        StringBuilder sb = new StringBuilder();
        for (String word : words) {
            sb.append(word.charAt(0));
        }

        if (s.equals(sb.toString())) {
            return true;
        }

        return false;
    }
}