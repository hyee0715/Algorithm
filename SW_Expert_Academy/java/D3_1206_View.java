import java.io.*;
import java.util.*;

class Solution {
    static int n;
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
        n = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++) {
            int a = Integer.parseInt(st.nextToken());

            nums.add(a);
        }
    }

    private static void solution() throws IOException {
        int answer = 0;

        for (int i = 2; i < nums.size() - 2; i++) {
            if (nums.get(i - 2) < nums.get(i) && nums.get(i - 1) < nums.get(i) && nums.get(i) > nums.get(i + 1) && nums.get(i) > nums.get(i + 2)) {
                int maxNeighbor = Math.max(Math.max(nums.get(i - 2), nums.get(i - 1)), Math.max(nums.get(i + 1), nums.get(i + 2)));
                answer += (nums.get(i) - maxNeighbor);
            }
        }

        bw.write(String.valueOf(answer));
    }
}