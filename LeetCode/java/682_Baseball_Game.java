class Solution {
    public int calPoints(String[] operations) {
        int answer = 0;
        List<Integer> list = new ArrayList<>();

        for (int i = 0; i < operations.length; i++) {
            if (operations[i].equals("C")) {
                list.remove(list.size() - 1);
                continue;
            }

            if (operations[i].equals("D")) {
                int n = list.get(list.size() - 1);
                list.add(n * 2);
                continue;
            }

            if (operations[i].equals("+")) {
                int a = list.get(list.size() - 1);
                int b = list.get(list.size() - 2);

                list.add(a + b);
                continue;
            }

            int n = Integer.parseInt(operations[i]);
            list.add(n);
        }

        for (int i = 0; i < list.size(); i++) {
            answer += list.get(i);
        }

        return answer;
    }
}