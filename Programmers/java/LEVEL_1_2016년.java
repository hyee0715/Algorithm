class Solution {
    public String solution(int a, int b) {
        String answer = "";

        int[] months = {-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        String[] days = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};

        int day = 0;

        for (int i = 1; i < a; i++) {
            day += months[i];
        }

        day += b;

        answer = days[day % 7];

        return answer;
    }
}