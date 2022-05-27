import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
        public static long a, b;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        a = Long.parseLong(st.nextToken());
        b = Long.parseLong(st.nextToken());

        bfs(a, 0);
    }

    public static void bfs(long a, int count) {
        Queue<Number> q = new LinkedList<>();
        Number number = new Number(a, count);
        q.add(number);

        while (!q.isEmpty()) {
            long n = q.peek().n;
            int cnt = q.peek().cnt;
            q.poll();

            if (n == b) {
                System.out.println(cnt + 1);
                return;
            }

            long nx = n * 2;
            if (nx <= b) {
                Number num1 = new Number(nx, cnt + 1);
                q.add(num1);
            }

            nx = (n * 10) + 1;
            if (nx <= b) {
                Number num2 = new Number(nx, cnt + 1);
                q.add(num2);
            }
        }

        System.out.println("-1");
    }
}

class Number {
    long n;
    int cnt;

    public Number(long n, int cnt) {
        this.n = n;
        this.cnt = cnt;
    }
}