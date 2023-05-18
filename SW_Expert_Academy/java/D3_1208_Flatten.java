import java.io.*;
import java.util.*;

class Solution {
    static int dumpCnt;
    static List<Integer> nums;

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        for (int i = 1; i <= 10; i++) {
            initialize();
            input();

            bw.write("#" + i + " ");
            solution();
            bw.write("\n");
        }

        bw.flush();
        bw.close();
    }

    private static void initialize() {
        nums = new ArrayList<>();
    }

    private static void input() throws IOException {
        dumpCnt = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < 100; i++) {
            int a = Integer.parseInt(st.nextToken());

            nums.add(a);
        }
    }

    private static void solution() throws IOException {
        for (int i = 0; i < dumpCnt; i++) {
            Collections.sort(nums);

            nums.set(0, nums.get(0) + 1);
            nums.set(nums.size() - 1, nums.get(nums.size() - 1) - 1);
        }

        Collections.sort(nums);
        int answer = nums.get(nums.size() - 1) - nums.get(0);

        bw.write(String.valueOf(answer));
    }
}