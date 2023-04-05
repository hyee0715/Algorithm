import java.util.Arrays;

class Solution {
    public double average(int[] salary) {
        double answer = 0;
        double sum = 0;

        Arrays.sort(salary);

        for (int i = 1; i < salary.length - 1; i++) {
            sum += salary[i];
        }

        answer = sum / (salary.length - 2);
        return answer;
    }
}