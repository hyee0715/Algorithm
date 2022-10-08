class Solution {
    public boolean isPrefixString(String s, String[] words) {
        StringBuilder sb = new StringBuilder();
        String str;

        for (int i = 0; i < words.length; i++) {
            sb.append(words[i]);

            str = sb.toString();

            if (str.equals(s))
                return true;
        }

        return false;
    }
}