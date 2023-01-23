import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution {
    public List<String> invalidTransactions(String[] transactions) {
        List<String> name = new ArrayList<>();
        List<String> city = new ArrayList<>();
        List<String> answer = new ArrayList<>();
        List<Integer> time = new ArrayList<>();
        List<Integer> amount = new ArrayList<>();
        boolean[] seen = new boolean[transactions.length];

        for (int i = 0; i < transactions.length; i++) {
            String[] temp = transactions[i].split(",");
            int cnt = 0;

            for (String s : temp) {
                if (cnt == 0) {
                    name.add(s);
                    cnt++;
                } else if (cnt == 1) {
                    time.add(Integer.parseInt(s));
                    cnt++;
                } else if (cnt == 2) {
                    amount.add(Integer.parseInt(s));
                    cnt++;
                } else {
                    city.add(s);
                }
            }
        }

        for (int i = 0; i < transactions.length; i++) {
            if (amount.get(i) > 1000) {
                answer.add(transactions[i]);
                seen[i] = true;
            }
        }

        Queue<Integer> q = new LinkedList<>();

        for (int i = 0; i < transactions.length - 1; i++) {
            for (int j = i + 1; j < transactions.length; j++) {
                if (Math.abs(time.get(i) - time.get(j)) <= 60) {
                    if (name.get(i).equals(name.get(j)) && !city.get(i).equals(city.get(j))) {
                        q.add(i);
                        q.add(j);
                    }
                }
            }
        }

        while (!q.isEmpty()) {
            int n = q.poll();

            if (!seen[n]) {
                answer.add(transactions[n]);
                seen[n] = true;
            }
        }

        return answer;
    }
}