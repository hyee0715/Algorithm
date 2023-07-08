import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Boolean> kidsWithCandies(int[] candies, int extraCandies) {
        List<Boolean> answer = new ArrayList<>();

        int maxNum = -1;

        for (int candy : candies) {
            maxNum = Math.max(maxNum, candy);
        }

        for (int candy : candies) {
            if (candy + extraCandies >= maxNum) {
                answer.add(true);
            } else {
                answer.add(false);
            }
        }

        return answer;
    }
}