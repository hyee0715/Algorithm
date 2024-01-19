import java.util.*;

class Solution {
    public char alphabet = 'a';

    public String solution(String m, String[] musicinfos) {
        String answer = "";
        List<Music> answers = new ArrayList<>();

        Map<String, Character> map = new HashMap<>(); //key: #이 들어간 음, value: 치환 알파벳

        m = replaceMelody(m, map);

        int sequence = 0;

        for (String music : musicinfos) {
            String[] infos = music.split(",");

            String melody = replaceMelody(infos[3], map);

            int playTime = getPlayTime(infos[0], infos[1]);

            String playLine = makePlayLine(playTime, melody);

            if (findNeoMusic(playLine, m)) {
                answers.add(new Music(infos[2], playTime, sequence)); //재생 시간, 입력 순서, 음악 제목
            }

            sequence++;
        }

        if (answers.size() == 0) {
            answer = "(None)"; // 조건이 일치하는 음악 없을 때는 (None) 반환
        } else if (answers.size() == 1) {
            answer = answers.get(0).getTitle();
        } else {
            answer = findAnswer(answers);
        }

        return answer;
    }

    private String replaceMelody(String melody, Map<String, Character> map) {
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < melody.length(); i++) {
            if (i < melody.length() - 1 && melody.charAt(i) != '#' && melody.charAt(i + 1) == '#') {
                StringBuilder s = new StringBuilder();
                s.append(melody.charAt(i));
                s.append(melody.charAt(i + 1));
                s.toString();

                if (map.containsKey(s.toString())) {
                    sb.append(map.get(s.toString()));
                } else {
                    map.put(s.toString(), alphabet);
                    sb.append(alphabet);

                    alphabet++;
                }

                i++;
                continue;
            }

            sb.append(melody.charAt(i));
        }

        return sb.toString();
    }

    private int getPlayTime(String start, String end) {
        String[] starts = start.split(":");
        String[] ends = end.split(":");

        int[] startTimes = {Integer.parseInt(starts[0]), Integer.parseInt(starts[1])};
        int[] endTimes = {Integer.parseInt(ends[0]), Integer.parseInt(ends[1])};

        if (endTimes[0] < startTimes[0]) {
            endTimes[0] = endTimes[0] + 24;
        }

        int startMinutes = startTimes[0] * 60 + startTimes[1];
        int endMinutes = endTimes[0] * 60 + endTimes[1];

        return endMinutes - startMinutes;
    }

    private String makePlayLine(int playTime, String score) {
        StringBuilder playLine = new StringBuilder();

        if (score.length() < playTime) { //곡의 길이가 재생시간보다 짧다면
            int copy = playTime / score.length();
            int plus = playTime % score.length();

            for (int i = 0; i < copy; i++) {
                playLine.append(score);
            }

            for (int i = 0; i < plus; i++) {
                playLine.append(score.charAt(i));
            }
        } else { //곡의 길이가 재생시간보다 길다면
            for (int i = 0; i < playTime; i++) {
                playLine.append(score.charAt(i));
            }
        }

        return playLine.toString();
    }

    private boolean findNeoMusic(String playLine, String melody) {
        if (playLine.length() < melody.length()) {
            return false;
        }

        StringBuilder cur = new StringBuilder();
        cur.append(playLine.substring(0, melody.length()));

        int idx = melody.length() - 1;

        while (idx < playLine.length()) {
            if (cur.toString().equals(melody)) {
                return true;
            }

            cur.deleteCharAt(0);
            idx++;

            if (idx == playLine.length()) {
                break;
            }

            cur.append(playLine.charAt(idx));
        }

        return false;
    }

    private String findAnswer(List<Music> musics) {
        Collections.sort(musics);

        return musics.get(0).getTitle();
    }
}

class Music implements Comparable<Music> {
    String title;
    int playTime;
    int sequence;

    Music(String title, int playTime, int sequence) {
        this.title = title;
        this.playTime = playTime;
        this.sequence = sequence;
    }

    String getTitle() {
        return this.title;
    }

    @Override
    public int compareTo(Music m) { // 재생 시간 제일 긴 순서, 재생 시간이 같을 경우 먼저 입력된 순서
        if (this.playTime < m.playTime) {
            return 1;
        }

        if (this.playTime > m.playTime) {
            return -1;
        }

        if (this.sequence < m.sequence) {
            return -1;
        }

        if (this.sequence > m.sequence) {
            return 1;
        }

        return 0;
    }
}