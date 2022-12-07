import java.util.HashMap;
import java.util.Map;

class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        String[] alphabet =  { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };

        Map<Character, String> map = new HashMap<>();
        Map<String, Integer> result = new HashMap<>();

        for (int i = 0; i < 26; i++) {
            map.put((char)(i + 'a'), alphabet[i]);
        }

        for (int i = 0; i < words.length; i++) {
            StringBuilder transformation = new StringBuilder();

            for (int j = 0; j < words[i].length(); j++) {
                transformation.append(map.get(words[i].charAt(j)));
            }

            result.put(transformation.toString(), result.getOrDefault(transformation.toString(), 0) + 1);
        }

        return result.size();
    }
}