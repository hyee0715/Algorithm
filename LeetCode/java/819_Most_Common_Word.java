import java.util.*;

class Solution {
    public String mostCommonWord(String paragraph, String[] banned) {
        StringBuilder sb = new StringBuilder();
        StringBuilder paragraphBuilder = new StringBuilder(paragraph);
        Set<String> set = new HashSet<>();
        Map<String, Integer> map = new HashMap<>();
        List<Word> list = new ArrayList<>();
        String answer = null;

        for (String ban : banned) {
            set.add(ban);
        }

        for (int i = 0; i < paragraph.length(); i++) {
            if (!(paragraph.charAt(i) >= 'a' && paragraph.charAt(i) <= 'z') && !(paragraph.charAt(i) >= 'A' && paragraph.charAt(i) <= 'Z')) {
                paragraphBuilder.setCharAt(i, ' ');
            }
        }

        for (int i = 0; i < paragraphBuilder.length() - 1; i++) {
            if (paragraphBuilder.charAt(i) == ' ' && paragraphBuilder.charAt(i + 1) == ' ') {
                paragraphBuilder.deleteCharAt(i);
            }
        }

        paragraph = paragraphBuilder.toString();

        paragraph = paragraph.toLowerCase();

        String[] arr = paragraph.split(" ");

        for (String a : arr) {
            map.put(a, map.getOrDefault(a, 0) + 1);
        }

        for (String key : map.keySet()) {
            Word word = new Word(map.get(key), key);
            list.add(word);
        }

        Collections.sort(list);

        for (int i = 0; i < list.size(); i++) {
            if (!set.contains(list.get(i).value)) {
                answer = list.get(i).value;
                break;
            }
        }

        return answer;
    }
}

class Word implements Comparable<Word> {
    int count;
    String value;

    Word(int count, String value) {
        this.count = count;
        this.value = value;
    }

    @Override
    public int compareTo(Word o) {
        if (this.count < o.count) {
            return 1;
        }

        if (this.count == o.count) {
            return 0;
        }

        return -1;
    }
}