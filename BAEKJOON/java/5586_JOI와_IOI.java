import java.io.*;

public class Main {
    public static String s;
    public static int joiCnt = 0, ioiCnt = 0;

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
       for (int i = 0; i < s.length() - 2; i++) {
           if (s.charAt(i) == 'J' && s.charAt(i + 1) == 'O' && s.charAt(i + 2) == 'I') {
               joiCnt++;
           }

           if (s.charAt(i) == 'I' && s.charAt(i + 1) == 'O' && s.charAt(i + 2) == 'I') {
               ioiCnt++;
           }
       }

       bw.write(joiCnt + "\n" + ioiCnt);
    }
}