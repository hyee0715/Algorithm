import java.io.*;
import java.util.*;

class Solution {
    static int n, q, tcNum = 1;

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int tc = Integer.parseInt(br.readLine());

        for (int i = 1; i <= tc; i++) {
            solution();
        }

        bw.flush();
        bw.close();
    }

    private static void solution() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        q = Integer.parseInt(st.nextToken());

        int[] boxes = new int[n + 1];

        int l, r;

        for (int i = 1; i <= q; i++) {
            st = new StringTokenizer(br.readLine());
            l = Integer.parseInt(st.nextToken());
            r = Integer.parseInt(st.nextToken());

            for (int j = l; j <= r; j++) {
                boxes[j] = i;
            }
        }

        bw.write("#" + tcNum + " ");

        for (int i = 1; i < boxes.length; i++) {
            bw.write(boxes[i] + " ");
        }
        bw.write("\n");

        tcNum++;
    }
}