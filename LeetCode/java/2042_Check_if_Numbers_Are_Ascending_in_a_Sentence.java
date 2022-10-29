import java.util.HashMap;

class Solution {
    public String kthDistinct(String[] arr, int k) {
        String answer = "";
        HashMap<String, Integer> hm = new HashMap<>();
        int cnt = 0;

        for (int i = 0; i < arr.length; i++) {
            hm.put(arr[i], hm.getOrDefault(arr[i], 0) + 1);
        }

        for (int i = 0; i < arr.length; i++) {
            if (hm.get(arr[i]) == 1) {
                cnt++;
            }

            if (cnt == k) {
                answer = arr[i];
                break;
            }
        }

        return answer;
    }
}