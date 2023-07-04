import java.util.List;

class Solution {
    public int countMatches(List<List<String>> items, String ruleKey, String ruleValue) {
        int answer = 0;

        int rule = 2;
        if (ruleKey.equals("type")) {
            rule = 0;
        } else if (ruleKey.equals("color")) {
            rule = 1;
        }

        for (List<String> item : items) {
            if (item.get(rule).equals(ruleValue)) {
                answer++;
            }
        }

        return answer;
    }
}