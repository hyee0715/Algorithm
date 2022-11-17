import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class Main {
    public static int n;
    public static long min_sum = Long.MAX_VALUE;
    public static List<Integer> nums = new ArrayList<>();
    public static List<Integer> answer = new ArrayList<>();

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        n = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            int a = Integer.parseInt(st.nextToken());
            nums.add(a);
        }
    }

    private static void findThirdElement(int first, int second) {
        int left = second + 1;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;

            long sum = 0;
            sum += nums.get(first);
            sum += nums.get(second);
            sum += nums.get(mid);

            if (Math.abs(sum) < Math.abs(min_sum)) {
                min_sum = sum;

                answer.clear();

                answer.add(nums.get(first));
                answer.add(nums.get(second));
                answer.add(nums.get(mid));
            }

            if (sum == 0) {
                return;
            }

            if (sum < 0) {
                left = mid + 1;
                continue;
            }

            if (sum > 0) {
                right = mid - 1;
            }
        }
    }

    private static void findSecondElement(int first) {
        for (int j = first + 1; j < nums.size() - 1; j++) {
            findThirdElement(first, j);
        }
    }

    private static void solution() throws IOException {
        Collections.sort(nums);

        for (int i = 0; i < nums.size() - 2; i++) {
            findSecondElement(i);
        }

        Collections.sort(answer);

        for (int n : answer) {
            bw.write(n + " ");
        }
    }
}