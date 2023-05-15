class Solution {
    public int longestBeautifulSubstring(String word) {
        int answer = 0;
        int cnt = 0;
        int currentLength = 0;

        for (int i = 0; i < word.length(); i++) {
            if (word.charAt(i) == 'a') {
                cnt++;
                currentLength++;
                char curChar = word.charAt(i);

                for (int j = i + 1; j < word.length(); j++) {
                    if (curChar == word.charAt(j)) {
                        currentLength++;
                    } else if (curChar < word.charAt(j)) {
                        currentLength++;
                        curChar = word.charAt(j);
                        cnt++;
                    } else {
                        cnt = 0;
                        currentLength = 0;

                        break;
                    }

                    if (cnt == 5) {
                        answer = Math.max(answer, currentLength);
                    }

                    i++;
                }
            }
        }

        return answer;
    }
}