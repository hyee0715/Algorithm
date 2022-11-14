class Solution {
    public String reformat(String s) {
        StringBuilder answer = new StringBuilder();
        List<Character> list1 = new ArrayList<>();
        List<Character> list2 = new ArrayList<>();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                list1.add(s.charAt(i));
                continue;
            }

            if (s.charAt(i) >= 'a' && s.charAt(i) <= 'z') {
                list2.add(s.charAt(i));
            }
        }

        if (list1.size() == 0 && list2.size() == 1) {
            answer.append(list2.get(0));
            return answer.toString();
        }

        if (list1.size() == 1 && list2.size() == 0) {
            answer.append(list1.get(0));
            return answer.toString();
        }

        if (list1.size() > list2.size() && list1.size() - list2.size() >= 2) {
            return answer.toString();
        }

        if (list2.size() > list1.size() && list2.size() - list1.size() >= 2) {
            return answer.toString();
        }

        if (list1.size() > list2.size()) {
            for (int i = 0; i < list2.size(); i++) {
                answer.append(list1.get(i));
                answer.append(list2.get(i));
            }

            answer.append(list1.get(list1.size() - 1));
        }

        if (list2.size() > list1.size()) {
            for (int i = 0; i < list1.size(); i++) {
                answer.append(list2.get(i));
                answer.append(list1.get(i));
            }

            answer.append(list2.get(list2.size() - 1));
        }

        if (list1.size() == list2.size()) {
            for (int i = 0; i < list1.size(); i++) {
                answer.append(list1.get(i));
                answer.append(list2.get(i));
            }
        }

        return answer.toString();
    }
}