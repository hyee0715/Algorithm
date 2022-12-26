class Solution {
    public String truncateSentence(String s, int k) {
        String[] arr = s.split(" ");
        String[] answer_arr = new String[k];

        for (int i = 0; i < k; i++) {
            answer_arr[i] = arr[i];
        }

        return String.join(" ", answer_arr);
    }
}