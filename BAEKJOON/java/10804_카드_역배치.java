import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static List<Integer> nums = new ArrayList<>();

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        solution();

        bw.flush();
        bw.close();
    }

    private static void solution() throws IOException {
        for (int i = 1; i <= 20; i++) {
            nums.add(i);
        }

        StringTokenizer st;
        for (int i = 0; i < 10; i++) {
            st = new StringTokenizer(br.readLine());

            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());

            List<Integer> temp = new ArrayList<>();

            for (int j = start - 1; j < end; j++) {
                temp.add(nums.get(j));
            }

            Collections.reverse(temp);

            int idx = 0;
            for (int j = start - 1; j < end; j++) {
                nums.set(j, temp.get(idx));
                idx++;
            }
        }

        for (int num : nums) {
            bw.write(num + " ");
        }
    }
}