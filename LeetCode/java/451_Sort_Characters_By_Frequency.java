import java.util.*;

class Solution {
    public String frequencySort(String s) {
        StringBuilder answer = new StringBuilder();
        Map<Character, Integer> map = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            map.put(s.charAt(i), map.getOrDefault(s.charAt(i), 0) + 1);
        }

        List<Pair> list = new ArrayList<>();
        for (char key : map.keySet()) {
            list.add(new Pair(map.get(key), key));
        }

        Collections.sort(list);

        for (int i = 0; i < list.size(); i++) {
            int n = list.get(i).getCount();

            for (int j = 0; j < n; j++) {
                answer.append(list.get(i).getAlphabet());
            }
        }

        return answer.toString();
    }
}

class Pair implements Comparable<Pair> {
    int count;
    char alphabet;

    Pair(int count, char alphabet) {
        this.count = count;
        this.alphabet = alphabet;
    }

    int getCount() {
        return count;
    }

    char getAlphabet() {
        return alphabet;
    }

    @Override
    public int compareTo(Pair o) {
        if (this.count < o.count) {
            return 1;
        }

        if (this.count > o.count) {
            return -1;
        }

        return 0;
    }
}