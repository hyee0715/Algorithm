import java.io.*;

public class Main {
    public static String s;
    public static StringBuilder n1 = new StringBuilder();
    public static StringBuilder n2 = new StringBuilder();

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        s = br.readLine();
    }

    private static void solution() throws IOException {
        if (s.length() == 4) {
            n1.append(s.charAt(0));
            n1.append(s.charAt(1));

            n2.append(s.charAt(2));
            n2.append(s.charAt(3));

            int ans1 = Integer.parseInt(n1.toString());
            int ans2 = Integer.parseInt(n2.toString());

            bw.write(String.valueOf(ans1 + ans2));
            return;
        }

        if (s.length() == 3) {
            if (s.charAt(0) == '1') {
                n1.append(s.charAt(0));
                n1.append(s.charAt(1));

                n2.append(s.charAt(2));

                int ans1 = Integer.parseInt(n1.toString());
                int ans2 = Integer.parseInt(n2.toString());

                bw.write(String.valueOf(ans1 + ans2));
                return;
            }

            if (s.charAt(0) != '1') {
                n1.append(s.charAt(0));

                n2.append(s.charAt(1));
                n2.append(s.charAt(2));

                int ans1 = Integer.parseInt(n1.toString());
                int ans2 = Integer.parseInt(n2.toString());

                bw.write(String.valueOf(ans1 + ans2));
                return;
            }
        }

        n1.append(s.charAt(0));
        n2.append(s.charAt(1));

        int ans1 = Integer.parseInt(n1.toString());
        int ans2 = Integer.parseInt(n2.toString());

        bw.write(String.valueOf(ans1 + ans2));
        return;
    }
}