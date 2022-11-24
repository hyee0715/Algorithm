import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {
    public static List<Integer> nums = new ArrayList<>();

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        for (int i = 0; i < 5; i++) {
            int n = Integer.parseInt(br.readLine());
            nums.add(n);
        }
    }

    private static void solution() throws IOException {
        Collections.sort(nums);

        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        int avg = sum / 5;
        int mid = nums.get(2);

        bw.write(avg + "\n" + mid);
    }
}