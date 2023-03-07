import java.util.Arrays;

class Solution {
    public long dividePlayers(int[] skill) {
        long answer = 0;
        long totalSum = 0;

        Arrays.sort(skill);

        for (int n : skill) {
            totalSum += n;
        }

        long subsetSum = totalSum / (skill.length / 2);

        int left = 0, right = skill.length - 1;

        while (left < right) {
            if (skill[left] + skill[right] != subsetSum) {
                return -1;
            }

            answer += (skill[left] * skill[right]);

            left++;
            right--;
        }

        return answer;
    }
}