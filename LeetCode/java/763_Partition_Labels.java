import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {
    public List<Integer> partitionLabels(String s) {
        List<Integer> answer = new ArrayList<>();

        List<Set<Character>> sv = new ArrayList<>();
        List<String> v = new ArrayList<>();

        Set<Character> st = new HashSet<>();
        st.add(s.charAt(0));
        sv.add(st);

        String str = "";
        str += s.charAt(0);
        v.add(str);

        for (int i = 1; i < s.length(); i++) {
            boolean flag = false;

            for (int j = 0; j < sv.size(); j++) {
                Set<Character> setchar = sv.get(j);
                if (setchar.contains(s.charAt(i))) {
                    //현재 문자가 어떠한 set에 존재하면
                    flag = true;

                    for (int k = j + 1; k < sv.size(); k++) {
                        for (char c : sv.get(k)) {
                            sv.get(j).add(c);
                        }

                        v.set(j, v.get(j) + v.get(k));
                    }

                    int size = sv.size();
                    for (int k = 1; k <= size - j - 1; k++) {
                        sv.remove(sv.size() - 1);
                        v.remove(v.size() - 1);
                    }

                    sv.get(j).add(s.charAt(i));
                    v.set(j, v.get(j) + s.charAt(i));

                    break;
                }
            }

            if (flag == false) {
                //모든 set에 존재하지 않으면
                st = new HashSet<>();
                str = "";

                st.add(s.charAt(i));
                sv.add(st);

                str += s.charAt(i);
                v.add(str);
            }
        }

        for (int i = 0; i < v.size(); i++) {
            answer.add(v.get(i).length());
        }

        return answer;
    }
}