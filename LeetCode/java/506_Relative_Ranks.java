import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

class Solution {
    public String[] findRelativeRanks(int[] score) {
        List<String> answer = new ArrayList<>();

        List<Pair<Integer, Integer>> v = new ArrayList<>();
        for (int i = 0; i < score.length; i++) {
            v.add(new Pair<>(score[i], i));
        }

        Collections.sort(v, (x, y) -> {
            if (x.getKey() < y.getKey()) {
                return 1;
            }

            if (x.getKey() > y.getKey()) {
                return -1;
            }

            return 0;
        });

        List<Pair<Integer, String>> temp = new ArrayList<>();
        for (int i = 0; i < v.size(); i++) {
            if (i == 0) {
                temp.add(new Pair<>(v.get(i).getValue(), "Gold Medal"));
            } else if (i == 1) {
                temp.add(new Pair<>(v.get(i).getValue(), "Silver Medal"));
            } else if (i == 2) {
                temp.add(new Pair<>(v.get(i).getValue(), "Bronze Medal"));
            } else {
                temp.add(new Pair<>(v.get(i).getValue(), String.valueOf(i + 1)));
            }
        }

        Collections.sort(temp, Comparator.comparingInt(Pair::getKey));

        for (Pair<Integer, String> t : temp) {
            answer.add(t.getValue());
        }

        return answer.toArray(new String[0]);
    }
}