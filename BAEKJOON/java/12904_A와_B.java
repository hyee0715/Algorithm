import java.io.*;

public class Main {
    public static String s, t;

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
        t = br.readLine();
    }

    private static void solution() throws IOException {
        // 반대로 t에서 s로 만들어본다.
        StringBuilder sb = new StringBuilder(s);
        StringBuilder st = new StringBuilder(t);

        while (sb.length() < st.length()) {
            if (st.charAt(st.length() - 1) == 'A') { // 문자열의 맨 뒤 값이 A이면 A를 제거한다.
               st.delete(st.length() - 1, st.length());
            } else { // 문자열의 맨 뒤 값이 B이면 제거하고 뒤집는다.
                st.delete(st.length() - 1, st.length());
                st.reverse();
            }
        }

        if (sb.toString().equals(st.toString())) {
            bw.write(String.valueOf(1));
        } else {
            bw.write(String.valueOf(0));
        }
    }
}