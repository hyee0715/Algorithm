import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

import static java.lang.Math.max;

public class Main {
   public static int n;
   public static long[] arr;
   public static long m, max_num = 0, answer = 0, sum = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());

        arr = new long[n];

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());

            sum += arr[i];

            if (max_num < arr[i])
                max_num = arr[i];
        }

        m = Integer.parseInt(br.readLine());

        Arrays.sort(arr);

        //모든 요청을 합한 값이 총 예산 m보다 작거나 같다면, 요청한 금액 중 가장 큰 값을 출력한 뒤 종료
        if (sum <= m) {
            System.out.println(max_num);
            System.exit(0);
        }

        //모든 요청을 합한 값이 총 예산 m보다 크다면, 배정할 예산의 상한액을 기준으로 이분탐색한다.
        long left = 0;
        long right = max_num;

        while (left <= right) {
            long mid = (left + right) / 2;

            if (binary_search(mid)) { // 요청 예산들 중 mid보다 큰 값들은 모두 mid로 바꾸고, 합계가 m보다 작거나 같다면 true 리턴. 예산 상한액을 더 올려본다.
                left = mid + 1;
                answer = max(answer, mid);
            }
            else { // M보다 크다면, 예산 상한액을 낮춘다.
                right = mid - 1;
            }
        }

        System.out.println(answer);
    }

    public static boolean binary_search(long target) {
        long sum_num = 0;
        long[] temp_arr = new long[n];

        for (int i = 0; i < n; i++) {
            temp_arr[i] = arr[i];
        }

        for (int i = 0; i < n; i++) {
            if (temp_arr[i] > target) {
                temp_arr[i] = target;
            }

            sum_num += temp_arr[i];
        }

        if (sum_num <= m)
            return true;
        return false;
    }
}
