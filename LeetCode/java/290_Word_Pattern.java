class Solution {
    public boolean wordPattern(String pattern, String s) {
        HashMap<Character, String> map1 = new HashMap<>();
        HashMap<String, Character> map2 = new HashMap<>();
        List<String> list = new ArrayList<>();
        StringBuilder s1 = new StringBuilder();
        StringBuilder s2 = new StringBuilder();
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ' ') {
                list.add(sb.toString());
                sb.setLength(0);
            } else {
                sb.append(s.charAt(i));
            }
        }

        if (sb.length() != 0) {
            list.add(sb.toString());
            sb.setLength(0);
        }

        if (pattern.length() != list.size())
            return false;

        for (int i = 0; i < pattern.length(); i++) {
            map1.put(pattern.charAt(i), list.get(i));
        }

        for (int i = 0; i < list.size(); i++) {
            map2.put(list.get(i), pattern.charAt(i));
        }

        for (int i = 0; i < pattern.length(); i++) {
            s2.append(map1.get(pattern.charAt(i)));

            if (i != pattern.length() - 1) {
                s2.append(" ");
            }
        }

        for (int i = 0; i < list.size(); i++) {
            s1.append(map2.get(list.get(i)));
        }

        if (s1.toString().equals(pattern) && s2.toString().equals(s))
            return true;

        return false;
    }
}