import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

import static java.lang.Math.max;

public class Main {
    public static int k, n;
    public static long[] arr;
    public static long max_num = 0, answer = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        k = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());

        arr = new long[k];

        for (int i = 0; i < k; i++) {
            arr[i] = Integer.parseInt(br.readLine());

            if (max_num < arr[i])
                max_num = arr[i];
        }

        // 만들(잘라낼) 랜선의 길이로 이분탐색
        Arrays.sort(arr);

        long left = 1;
        long right = max_num;

        while (left <= right) {
            long mid = (left + right) / 2;

            if (binary_search(mid)) { // 갖고있는 랜선을 각각 mid의 길이만큼 잘라낸 개수가 n개 이상이면, mid의 길이를 더 늘려볼 수 있다.
                left = mid + 1;
                answer = max(answer, mid);
            }
            else { // 갖고있는 랜선을 각각 mid의 길이만큼 잘라낸 랜선의 개수가 n개 미만이면, mid의 길이를 줄인다.
                right = mid - 1;
            }
        }

        System.out.println(answer);
    }

    public static Boolean binary_search(long target) {
        long sum = 0;

        for (int i = 0; i < k; i++) {
            sum += (arr[i] / target);
        }

        if (sum >= n)
            return true;
        return false;
    }
}
