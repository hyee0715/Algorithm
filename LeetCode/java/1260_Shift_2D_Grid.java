import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        List<List<Integer>> answer = new ArrayList<>();

        int idx = 0;
        int[] list = new int[grid.length * grid[0].length];
        for (int[] g : grid) {
            for (int n : g) {
                list[idx++] = n;
            }
        }

        while (k > 0) {
            int prev = list[list.length - 1];
            int temp = -1;
            for (int i = 0; i < list.length - 1; i++) {
                temp = list[i];
                list[i] = prev;
                prev = temp;
            }

            list[list.length - 1] = prev;

            k--;
        }

        List<Integer> temp = new ArrayList<>();
        int col = 0;

        for (int i = 0; i < list.length; i++) {
            if (col == grid[0].length) {
                answer.add(temp);
                temp = new ArrayList<>();
                col = 0;
            }

            temp.add(list[i]);
            col++;
        }

        answer.add(temp);

        return answer;
    }
}