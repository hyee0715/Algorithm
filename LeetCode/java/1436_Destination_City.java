import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public String destCity(List<List<String>> paths) {
        String answer = "";
        Map<String, List<String>> map = new HashMap<>();

        for (List<String> path : paths) {
            if (!map.containsKey(path.get(0))) {
                map.put(path.get(0), new ArrayList<>());
            }

            map.get(path.get(0)).add(path.get(1));
        }

        for (List<String> path : paths) {
            if (!map.containsKey(path.get(1))) {
                answer = path.get(1);
            }
        }

        return answer;
    }
}