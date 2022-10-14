class Solution {
    public String toGoatLatin(String sentence) {
        StringBuilder answer = new StringBuilder();
        StringBuilder sb = new StringBuilder();
        List<String> list = new ArrayList<>();

        for (int i = 0; i < sentence.length(); i++) {
            if (sentence.charAt(i) == ' ') {
                list.add(sb.toString());
                sb.setLength(0);
            } else {
                sb.append(sentence.charAt(i));
            }
        }

        if (sb.length() != 0) {
            list.add(sb.toString());
        }

        for (int i = 0; i < list.size(); i++) {
            sb.setLength(0);

            if (list.get(i).charAt(0) != 'a' && list.get(i).charAt(0) != 'i' && list.get(i).charAt(0) != 'u' && list.get(i).charAt(0) != 'e' && list.get(i).charAt(0) != 'o' && list.get(i).charAt(0) != 'A' && list.get(i).charAt(0) != 'I' && list.get(i).charAt(0) != 'U' && list.get(i).charAt(0) != 'E' && list.get(i).charAt(0) != 'O') {
                for (int j = 1; j < list.get(i).length(); j++) {
                    sb.append(list.get(i).charAt(j));
                }

                sb.append(list.get(i).charAt(0));

                list.set(i, sb.toString());
            }
        }

        for (int i = 0; i < list.size(); i++) {
            answer.append(list.get(i));
            answer.append("ma");

            for (int j = 0; j <= i; j++) {
                answer.append("a");
            }

            if (i != (list.size() - 1))
                answer.append(" ");
        }

        return answer.toString();
    }
}