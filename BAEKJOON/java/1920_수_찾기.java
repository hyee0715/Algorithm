import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static int n, m;
    public static List<Integer> answer = new ArrayList<>();
    public static long[] nArr, mArr;
    public static boolean flag;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        nArr = new long[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            nArr[i] = Long.parseLong(st.nextToken());
        }

        m = Integer.parseInt(br.readLine());
        mArr = new long[m];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < m; i++) {
            mArr[i] = Long.parseLong(st.nextToken());
        }

        Arrays.sort(nArr);

        for (int i = 0; i < m; i++) {
            int left = 0;
            int right = n - 1;
            flag = false;

            while (left <= right) {
                int mid = (left + right) / 2;

                if (nArr[mid] == mArr[i]) {
                    answer.add(1);
                    flag = true;
                    break;
                }
                else if (nArr[mid] > mArr[i]) {
                    right = mid - 1;
                } else { //nArr[mid] < mArr[i]
                    left = mid + 1;
                }
            }

            if (!flag)
                answer.add(0);
        }

        for (int i : answer) {
            System.out.println(i);
        }
    }
}

