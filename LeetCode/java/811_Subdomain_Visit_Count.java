import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        List<String> answer = new ArrayList<>();
        Map<String, Integer> map = new HashMap<>();

        for (String cpdomain : cpdomains) {
            String[] sep = cpdomain.split(" ");

            extract(sep, map);
        }

        for (String key : map.keySet()) {
            String s = String.valueOf(map.get(key)) + " " + key;
            answer.add(s);
        }

        return answer;
    }

    void extract(String[] sep, Map<String, Integer> map) {
        int num = Integer.parseInt(sep[0]);
        String s = sep[1];

        StringBuilder temp = new StringBuilder();
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == '.') {
                map.put(temp.toString(), map.getOrDefault(temp.toString(), 0) + num);
            }

            StringBuilder sb = new StringBuilder(String.valueOf(s.charAt(i)));
            sb.append(temp.toString());
            temp = sb;
        }

        map.put(temp.toString(), map.getOrDefault(temp.toString(), 0) + num);
    }
}