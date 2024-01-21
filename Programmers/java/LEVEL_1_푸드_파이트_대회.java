class Solution {
    public String solution(int[] food) {
        String answer = "0";
        char foodNum = (char)((food.length - 1) + '0');

        for (int i = food.length - 1; i >= 0; i--) {
            int count = food[i] / 2;

            for (int j = 0; j < count; j++) {
                answer = foodNum + answer + foodNum;
            }

            foodNum--;
        }

        return answer;
    }
}