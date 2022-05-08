import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static int n, cnt = 0;
    public static int[] cow = new int[11];
    public static List<Pair> list = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            list.add(new Pair(a, b));
        }

        Arrays.fill(cow, -1);

        for (int i = 0; i < list.size(); i++) {
            if (cow[list.get(i).getCowNum()] == -1) {
                cow[list.get(i).getCowNum()] = list.get(i).getSide();
            } else {
                if (cow[list.get(i).getCowNum()] == 0 && list.get(i).getSide() == 1) {
                    cnt++;
                    cow[list.get(i).getCowNum()] = list.get(i).getSide();
                } else if (cow[list.get(i).getCowNum()] == 1 && list.get(i).getSide() == 0) {
                    cnt++;
                    cow[list.get(i).getCowNum()] = list.get(i).getSide();
                }
            }
        }

        System.out.println(cnt);
    }
}

class Pair {
    int cowNum;
    int side;

    public Pair(int cowNum, int side) {
        this.cowNum = cowNum;
        this.side = side;
    }

    public int getCowNum() {
        return cowNum;
    }

    public int getSide() {
        return side;
    }
}
