import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static int n, answer = 0;
    public static String winner, win_answer;
    public static List<Quiz> list = new ArrayList<>();

    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        input();
        solution();

        bw.flush();
        bw.close();
    }

    private static void input() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        winner = st.nextToken();

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());

            String participant = st.nextToken();
            String answer = st.nextToken();

            Quiz quiz = new Quiz(participant, answer);

            list.add(quiz);
        }
    }

    private static void solution() throws IOException {
        for (int i = list.size() - 1; i >= 0; i--) {
            if (list.get(i).participant.equals(winner)) {
                win_answer = list.get(i).answer;
                continue;
            }

            if (list.get(i).answer.equals(win_answer)) {
                answer++;
            }
        }

        bw.write(String.valueOf(answer));
    }
}

class Quiz {
    String participant;
    String answer;

    public Quiz(String participant, String answer) {
        this.participant = participant;
        this.answer = answer;
    }
}