class Solution {
    public List<String> stringMatching(String[] words) {
        Set<String> set = new HashSet<>();
        List<String> answer = new ArrayList<>();

        for (int i = 0; i < words.length; i++) {
            for (int j = 0; j < words.length; j++) {
                if (i == j) {
                    continue;
                }

                if (words[j].contains(words[i])) {
                    set.add(words[i]);
                }
            }
        }

        for (String s : set) {
            answer.add(s);
        }

        return answer;
    }
}