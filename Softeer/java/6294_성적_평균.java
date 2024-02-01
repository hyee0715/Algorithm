import java.io.*;
import java.util.*;

public class Main {
    
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static int n, k; //학생 수, 구간 수
    
    
    public static void main(String[] args) throws IOException {
        solution();

        bw.flush();
        bw.close();
    }

    private static void solution() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());

        int[] score = new int[n + 1];
        st = new StringTokenizer(br.readLine());
        
        int idx = 1;
        for (int i = 0; i < n; i++) {
            score[idx++] = Integer.parseInt(st.nextToken());
        }

        int[] cumul = new int[score.length];

        settingCumulativeSum(score, cumul);
        
        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(br.readLine());

            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());

            int sum = getSum(start, end, cumul);

            double answer = getAvg(sum, end - start + 1);

            bw.write(String.format("%.2f", answer) + "\n");
        }
    }

    private static int getSum(int start, int end, int[] cumul) {
        if (start == 1) {
                return cumul[end];
            }
        
        return cumul[end] - cumul[start - 1];
    }
    
    private static void settingCumulativeSum(int[] score, int[] cumul) {
        cumul[1] = score[1];
        
        for (int i = 2; i < score.length; i++) {
            cumul[i] = cumul[i - 1] + score[i];
        }
    }

    private static double getAvg(int sum, int num) {

        return (double)sum / num;
    }
}
