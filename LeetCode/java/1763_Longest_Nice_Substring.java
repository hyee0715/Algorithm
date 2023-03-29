import java.util.HashMap;
import java.util.Map;

class Solution {
    private boolean check(Map<Character, Integer> low, Map<Character, Integer> hi) {
        for (char key : low.keySet()) {
            if (hi.getOrDefault((char)(key - 32), 0) == 0) {
                return false;
            }
        }

        for (char key : hi.keySet()) {
            if (low.getOrDefault((char)(key + 32), 0) == 0) {
                return false;
            }
        }

        return true;
    }

    public String longestNiceSubstring(String s) {
        Map<Character, Integer> low = new HashMap<>();
        Map<Character, Integer> hi = new HashMap<>();
        String answer = "";

        for (int i = 0; i < s.length(); i++) {
            low = new HashMap<>();
            hi = new HashMap<>();

            for (int j = i; j < s.length(); j++) {
                if (s.charAt(j) >= 'a' && s.charAt(j) <= 'z') {
                    low.put(s.charAt(j), low.getOrDefault(s.charAt(j), 0) + 1);
                } else {
                    hi.put(s.charAt(j), hi.getOrDefault(s.charAt(j), 0) + 1);
                }

                if (check(low, hi)) {
                    if (j - i + 1 > answer.length()) {
                        answer = s.substring(i, j + 1);
                    }
                }
            }
        }

        return answer;
    }
}class Solution {
    private boolean check(Map<Character, Integer> low, Map<Character, Integer> hi) {
        for (char key : low.keySet()) {
            if (hi.getOrDefault((char)(key - 32), 0) == 0) {
                return false;
            }
        }

        for (char key : hi.keySet()) {
            if (low.getOrDefault((char)(key + 32), 0) == 0) {
                return false;
            }
        }

        return true;
    }

    public String longestNiceSubstring(String s) {
        Map<Character, Integer> low = new HashMap<>();
        Map<Character, Integer> hi = new HashMap<>();
        String answer = "";

        for (int i = 0; i < s.length(); i++) {
            low = new HashMap<>();
            hi = new HashMap<>();

            for (int j = i; j < s.length(); j++) {
                if (s.charAt(j) >= 'a' && s.charAt(j) <= 'z') {
                    low.put(s.charAt(j), low.getOrDefault(s.charAt(j), 0) + 1);
                } else {
                    hi.put(s.charAt(j), hi.getOrDefault(s.charAt(j), 0) + 1);
                }

                if (check(low, hi)) {
                    if (j - i + 1 > answer.length()) {
                        answer = s.substring(i, j + 1);
                    }
                }
            }
        }

        return answer;
    }
}