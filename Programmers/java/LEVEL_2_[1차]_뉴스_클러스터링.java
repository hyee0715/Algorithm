import java.util.*;

class Solution {
    public int solution(String str1, String str2) {
        int answer = 0;

        //대문자로 통일
        str1 = str1.toUpperCase();
        str2 = str2.toUpperCase();

        //Map 세팅
        Map<String, Integer> map1 = new HashMap<>();
        Map<String, Integer> map2 = new HashMap<>();

        settingMap(map1, str1);
        settingMap(map2, str2);

        //두 문자열의 교집합과 합집합 구하기
        List<String> stringIntersection = getIntersection(map1, map2);
        List<String> stringUnion = getUnion(map1, map2);

        int intersecNum = stringIntersection.size();
        int unionNum = stringUnion.size();

        double jaccardSimilarity = 0;

        if (intersecNum == 0 && unionNum == 0) {
            jaccardSimilarity = 1;
        } else {
            jaccardSimilarity = (double)intersecNum / unionNum;
        }

        answer = (int)(jaccardSimilarity * 65536);

        return answer;
    }

    void settingMap(Map<String, Integer> map, String s) {
        for (int i = 0; i < s.length() - 1; i++) {
            if (!(s.charAt(i) >= 'a' && s.charAt(i) <= 'z') && !(s.charAt(i) >= 'A' && s.charAt(i) <= 'Z')) {
                continue;
            }

            if (!(s.charAt(i + 1) >= 'a' && s.charAt(i + 1) <= 'z') && !(s.charAt(i + 1) >= 'A' && s.charAt(i + 1) <= 'Z')) {
                continue;
            }

            String str = "";
            str += s.charAt(i);
            str += s.charAt(i + 1);

            map.put(str, map.getOrDefault(str, 0) + 1);
        }
    }

    List<String> getIntersection(Map<String, Integer> map1, Map<String, Integer> map2) {
        List<String> intersection = new ArrayList<>();

        for (String key : map1.keySet()) {
            String map1Name = key;
            int map1Cnt = map1.get(key);

            if (map2.containsKey(map1Name)) {
                int map2Cnt = map2.get(map1Name);

                int size = Math.min(map1Cnt, map2Cnt);

                for (int i = 0; i < size; i++) {
                    intersection.add(map1Name);
                }
            }
        }

        return intersection;
    }

    List<String> getUnion(Map<String, Integer> map1, Map<String, Integer> map2) {
        List<String> retUnion = new ArrayList<>();

        for (String key : map1.keySet()) {
            String map1Name = key;
            int map1Cnt = map1.get(map1Name);

            if (map2.containsKey(map1Name)) {
                int map2Cnt = map2.get(map1Name);

                int size = Math.max(map1Cnt, map2Cnt);

                for (int i = 0; i < size; i++) {
                    retUnion.add(map1Name);
                }
            } else {
                for (int i = 0; i < map1Cnt; i++) {
                    retUnion.add(map1Name);
                }
            }
        }

        for (String key : map2.keySet()) {
            String map2Name = key;
            int map2Cnt = map2.get(map2Name);

            if (map1.containsKey(map2Name)) {
                continue;
            }

            for (int i = 0; i < map2Cnt; i++) {
                retUnion.add(map2Name);
            }
        }

        return retUnion;
    }
}