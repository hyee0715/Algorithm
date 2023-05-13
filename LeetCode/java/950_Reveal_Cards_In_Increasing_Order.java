import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;

class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        int[] answer = new int[deck.length];
        Deque<Integer> dq = new ArrayDeque<>();

        Arrays.sort(deck);

        for (int i = deck.length - 1; i >= 0; i--) {
            if (!dq.isEmpty()) {
                int n = dq.pollLast();
                dq.offerFirst(n);
            }

            dq.offerFirst(deck[i]);
        }

        int idx = 0;
        while (!dq.isEmpty()) {
            answer[idx++] = dq.pollFirst();
        }

        return answer;
    }
}