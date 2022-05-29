import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Math.max;

public class Main {
    public static int m, n;
    public static long[] arr;
    public static long max_num = 0, answer;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        arr = new long[n + 1];

        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            arr[i] = Long.parseLong(st.nextToken());

            if (max_num < arr[i]) {
                max_num = arr[i];
            }
        }

        long start = 1;
        long end = max_num;

        while (start <= end) {
            long mid = (start + end) / 2;

            if (binary_search(mid)) {
                start = mid + 1;
                answer = max(answer, mid);
            } else {
                end = mid - 1;
            }
        }

        System.out.println(answer);
    }

    public static boolean binary_search(long target) {
        long cnt = 0;

        for (int i = 1; i <= n; i++) {
            cnt += arr[i] / target;
        }

        if (cnt >= m)
            return true;
        return false;
    }
}