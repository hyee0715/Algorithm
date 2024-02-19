import java.util.*;

class Solution {
    List<String> colComb = new ArrayList<>(); //유일성을 만족하는 컬럼 조합
    Set<String> set = new HashSet<>();

    public int solution(String[][] relation) {
        int answer = 0;

        String[] columns = new String[relation[0].length];

        char alphabet = 'a';
        for (int i = 0; i < relation[0].length; i++) {
            columns[i] = String.valueOf((char)(alphabet + i));
        }

        int[] indexes = new int[relation[0].length];

        for (int i = 0; i < relation[0].length; i++) {
            indexes[i] = i;
        }

        List<Integer> list = new ArrayList<>();
        boolean[] visit = new boolean[indexes.length];

        for (int i = 1; i <= relation[0].length; i++) {
            getCombination(0, 0, i, list, visit, indexes, relation, columns);
        }

        answer = findMinimalityCount();

        return answer;
    }

    private int findMinimalityCount() {
        boolean[] isInvalid = new boolean[colComb.size()];

        for (int i = 0; i < colComb.size() - 1; i++) {
            for (int j = i + 1; j < colComb.size(); j++) {
                if (i == j || isInvalid[i] == true || isInvalid[j] == true) {
                    continue;
                }

                String a = colComb.get(i);
                String b = colComb.get(j);

                if (a.length() < b.length()) {
                    if (validateChar(a, b)) {
                        isInvalid[j] = true;
                    }
                }

                if (a.length() > b.length()) {
                    if (validateChar(b, a)) {
                        isInvalid[i] = true;
                    }
                }
            }
        }

        int cnt = 0;
        for (boolean flag : isInvalid) {
            if (!flag) {
                cnt++;
            }
        }

        return cnt;
    }

    private boolean validateChar(String a, String b) {
        for (int i = 0; i < a.length(); i++) {
            if (!b.contains(String.valueOf(a.charAt(i)))) {
                return false;
            }
        }

        return true;
    }

    private void getCombination(int idx, int cnt, int limit, List<Integer> list, boolean[] visit, int[] indexes, String[][] relation, String[] columns) {
        if (cnt == limit) {
            set.clear();

            List<String> combinations = makeStr(list, relation);

            for (String combination : combinations) {
                set.add(combination);
            }

            if (set.size() == relation.length) {
                StringBuilder sb = new StringBuilder();

                for (int n : list) {
                    sb.append(columns[n]);
                }

                colComb.add(sb.toString());
            }

            return;
        } else {
            for (int i = idx; i < indexes.length; i++) {
                if (visit[i] == true) continue;
                visit[i] = true;
                list.add(indexes[i]);
                getCombination(i, cnt + 1, limit, list, visit, indexes, relation, columns);
                visit[i] = false;
                list.remove(list.size() - 1);
            }
        }
    }

    private List<String> makeStr(List<Integer> list, String[][] relation) {
        List<String> ret = new ArrayList<>();

        for (String[] rel : relation) {
            String comb = getStringFormatCombination(list, rel);

            ret.add(comb);
        }

        return ret;
    }

    private String getStringFormatCombination(List<Integer> list, String[] relation) {
        StringBuilder sb = new StringBuilder();

        for (int idx : list) {
            sb.append(relation[idx]);
        }

        return sb.toString();
    }
}