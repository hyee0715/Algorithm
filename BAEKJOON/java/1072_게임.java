import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

import static java.lang.Math.max;
import static java.lang.Math.min;

public class Main {
    public static long x, y, z, answer = Long.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        x = Long.parseLong(st.nextToken());
        y = Long.parseLong(st.nextToken());

        // 원래 승률 z 구하기. 99 또는 100이면 승률을 더이상 높이지 못하므로 -1 출력 후 종료.
        z = (y * 100) / x;

        if (z == 99 || z == 100) {
            System.out.println("-1");
            return;
        }

        // 앞으로 할 게임의 이긴 게임의 수로 이분탐색한다. (앞으로의 모든 게임에서 지지 않는다.)
        long left = 1;
        long right = 1000000000;

        while (left <= right) {
            long mid = (left + right) / 2;

            if (binary_search(mid)) { // 원래 승률 z와 새로 구한 승률 temp_z가 다르면 앞으로 할 게임의 수를 낮춰본다.
                right = mid - 1;
                answer = min(answer, mid);
            }
            else { // 원래 승률 z와 새로 구한 승률 temp_z가 다르면 앞으로 할 게임의 수를 높인다.
                left = mid + 1;
            }
        }

        System.out.println(answer);
    }

    public static boolean binary_search(long target) {
        long temp_z = ((y + target) * 100) / (x + target);

        if (temp_z != z)
            return true;
        return false;
    }
}
