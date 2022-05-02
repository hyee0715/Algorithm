import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

import static java.lang.Math.max;

public class Main {
    public static int n;
    public static long[] arr;
    public static long m, max_num = 0, answer = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        arr = new long[n];

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());

            if (max_num < arr[i])
                max_num = arr[i];
        }

        // 절단기의 높이로 이분탐색한다. (자를 나무의 최대 높이)
        Arrays.sort(arr);

        long left = 0;
        long right = max_num;

        while (left <= right) {
            long mid = (left + right) / 2;

            if (binary(mid)) { // 자른 나무의 합계가 m미터 이상이면 높이를 더 늘려보기(나무의 합계 줄이기)
                left = mid + 1;
                answer = max(answer, mid);
            }
            else { // 자른 나무의 합계가 m미터 미만이면 높이 줄이기(나무 합계 늘리기)
                right = mid - 1;
            }
        }

        System.out.println(answer);
    }

    public static Boolean binary(long target) {
        long sum = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] >= target)
                sum += (arr[i] - target);
        }

        if (sum >= m)
            return true;
        return false;
    }
}
