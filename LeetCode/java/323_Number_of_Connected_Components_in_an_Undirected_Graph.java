import java.util.*;

class Solution {
    public int[] solution(String[] gems) {
        int[] answer = new int[]{-1, -1};
        Map<String, Integer> mp = new HashMap<>();

        int minNum = 100001;

        for (String g : gems) {
            mp.put(g, mp.getOrDefault(g, 0) + 1);
        }

        int count = mp.size(); //보석 종류 수

        int left = 1, right = gems.length;;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int[] list = check(gems, mid, count);
            if (list[0] != -1 && list[1] != -1) {
                if (minNum > list[1] - list[0] + 1) {
                    minNum = list[1] - list[0] + 1;
                    answer = new int[]{list[0], list[1]};
                }

                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return answer;
    }

    int[] check(String[] gems, int count, int target) {
        Map<String, Integer> checkMap = new HashMap<>();

        int left = 0, right = count - 1;

        for (int i = left; i <= right; i++) {
            checkMap.put(gems[i], checkMap.getOrDefault(gems[i], 0) + 1);
        }

        if (checkMap.size() == target) {
            return new int[]{left + 1, right + 1};
        }

        while (right < gems.length) {
            if (checkMap.size() == target) {
                return new int[]{left + 1, right + 1};
            }

            checkMap.put(gems[left], checkMap.get(gems[left]) - 1);

            if (checkMap.get(gems[left]) == 0) {
                checkMap.remove(gems[left]);
            }

            left++;
            right++;

            if (right == gems.length) {
                break;
            }

            checkMap.put(gems[right], checkMap.getOrDefault(gems[right], 0) + 1);
        }

        if (checkMap.size() == target) {
            return new int[]{left + 1, right + 1};
        }

        return new int[]{-1, -1};
    }
}