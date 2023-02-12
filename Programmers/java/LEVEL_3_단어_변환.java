import java.util.*;

class Solution {
    private boolean check(String a, String b) {
        int diff = 0;

        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) {
                diff++;
            }
        }

        if (diff == 1) {
            return true;
        }
        return false;
    }

    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        boolean[] visit = new boolean[words.length];

        Queue<Pair> q = new LinkedList<>();
        Pair pair = new Pair(begin, 0);
        q.add(pair);

        while (!q.isEmpty()) {
            pair = q.poll();
            String word = pair.getWord();
            int cnt = pair.getCount();

            if (word.equals(target)) {
                answer = cnt;
                break;
            }

            for (int i = 0; i < words.length; i++) {
                if (visit[i] == false && check(word, words[i])) {
                    visit[i] = true;
                    pair = new Pair(words[i], cnt + 1);
                    q.add(pair);
                }
            }
        }

        return answer;
    }
}

class Pair {
    String word;
    int count;

    Pair(String word, int count) {
        this.word = word;
        this.count = count;
    }

    String getWord() {
        return word;
    }

    int getCount() {
        return count;
    }
}