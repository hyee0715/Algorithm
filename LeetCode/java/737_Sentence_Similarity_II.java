import java.util.*;

class Solution {
    public static int[] parent;

    public boolean areSentencesSimilarTwo(String[] sentence1, String[] sentence2, List<List<String>> similarPairs) {
        if (sentence1.length != sentence2.length) {
            return false;
        }

        Set<String> set = new HashSet<>();
        Map<String, Integer> map = new HashMap<>(); //단어, parent인덱스

        settingSet(set, similarPairs);
        settingSet(set, sentence1);
        settingSet(set, sentence2);

        parent = new int[set.size()];
        initializeParentArray();

        settingMap(set, map);

        unionSimilarPairs(similarPairs, map);

        for (int i = 0; i < sentence1.length; i++) {
            if (!map.containsKey(sentence1[i]) || !map.containsKey(sentence2[i])) {
                return false;
            }

            int sen1Idx = map.get(sentence1[i]);
            int sen2Idx = map.get(sentence2[i]);

            if (!sameParent(sen1Idx, sen2Idx)) {
                return false;
            }
        }

        return true;
    }

    private void unionSimilarPairs(List<List<String>> similarPairs, Map<String, Integer> map) {
        for (List<String> pairs : similarPairs) {
            String a = pairs.get(0);
            String b = pairs.get(1);

            int aIdx = map.get(a);
            int bIdx = map.get(b);

            if (!sameParent(aIdx, bIdx)) {
                unionParent(aIdx, bIdx);
            }
        }
    }

    private void settingMap(Set<String> set, Map<String, Integer> map) {
        int idx = 0;

        for (String word : set) {
            map.put(word, idx++);
        }
    }

    private void initializeParentArray() {
        for (int i = 0; i < parent.length; i++) {
            parent[i] = i;
        }
    }

    private void settingSet(Set<String> set, List<List<String>> similarPairs) {
        for (List<String> pairs : similarPairs) {
            set.add(pairs.get(0));
            set.add(pairs.get(1));
        }
    }

    private void settingSet(Set<String> set, String[] sentence) {
        for (String s : sentence) {
            set.add(s);
        }
    }

    private int findParent(int x) {
        if (parent[x] == x) {
            return x;
        }

        int ret = findParent(parent[x]);
        return ret;
    }

    private boolean sameParent(int x, int y) {
        x = findParent(x);
        y = findParent(y);

        if (x == y) {
            return true;
        }

        return false;
    }

    private void unionParent(int x, int y) {
        x = findParent(x);
        y = findParent(y);

        if (x < y) {
            parent[y] = x;
        } else {
            parent[x] = y;
        }
    }
}