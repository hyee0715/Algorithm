import java.util.*;

class Solution {
    String[] op = {"+", "-", "*"};
    List<String> seq = new ArrayList<>();

    public long solution(String expression) {
        long answer = 0;

        boolean[] visit = new boolean[op.length];
        StringBuilder sb = new StringBuilder();

        getSeq(0, visit, sb);

        List<String> expressions = splitExpression(expression);

        for (int i = 0; i < seq.size(); i++) {
            List<String> cal = new ArrayList<>();
            List<String> temp = new ArrayList<>();

            for (int j = 0; j < expressions.size(); j++) {
                temp.add(expressions.get(j));
            }

            for (int j = 0; j < seq.get(i).length(); j++) {
                String op = String.valueOf(seq.get(i).charAt(j));

                for (int k = 0; k < temp.size(); k++) {
                    String element = temp.get(k);

                    if (element.equals(op)) {
                        long a = Long.parseLong(cal.get(cal.size() - 1));
                        long b = Long.parseLong(temp.get(k + 1));

                        long result = calculate(a, b, element);

                        cal.remove(cal.size() - 1);
                        k++;
                        cal.add(String.valueOf(result));
                    } else {
                        cal.add(element);
                    }
                }

                temp.clear();

                for (String ex : cal) {
                    temp.add(ex);
                }

                cal.clear();
            }

            long absNum = Math.abs(Long.parseLong(temp.get(0)));
            answer = Math.max(answer, absNum);
        }

        return answer;
    }

    private long calculate(long a, long b, String op) {
        if (op.equals("+")) {
            return a + b;
        }

        if (op.equals("-")) {
            return a - b;
        }

        return a * b;
    }

    private void getSeq(int cnt, boolean[] visit, StringBuilder sb) {
        if (cnt == op.length) {
            seq.add(sb.toString());

            return;
        } else {
            for (int i = 0; i < op.length; i++) {
                if (visit[i] == true) continue;
                visit[i] = true;
                sb.append(op[i]);
                getSeq(cnt + 1, visit, sb);
                sb.deleteCharAt(sb.length() - 1);
                visit[i] = false;
            }
        }
    }

    private List<String> splitExpression(String ex) {
        List<String> ret = new ArrayList<>();
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < ex.length(); i++) {
            if (ex.charAt(i) == '-' || ex.charAt(i) == '+' || ex.charAt(i) == '*') {
                ret.add(sb.toString());

                sb.setLength(0);

                ret.add(String.valueOf(ex.charAt(i)));
            } else {
                sb.append(ex.charAt(i));
            }
        }

        ret.add(sb.toString());

        return ret;
    }
}