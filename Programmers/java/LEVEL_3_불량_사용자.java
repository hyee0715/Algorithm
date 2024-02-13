import java.util.*;

class Solution {
    List<String[]> list = new ArrayList<>();
    List<String> strList = new ArrayList<>();

    public int solution(String[] user_id, String[] banned_id) {
        int answer = 0;

        int listSize = banned_id.length;
        boolean[] visit = new boolean[user_id.length];

        getList(0, listSize, user_id, visit);

        List<String[]> bannedList = searchBannedId(list, banned_id);

        answer = getBannedSize(bannedList);

        return answer;
    }

    private int getBannedSize(List<String[]> bannedList) {
        Set<String> set = new HashSet<>();

        for (String[] s : bannedList) {
            Arrays.sort(s);

            StringBuilder sb = new StringBuilder();

            for (int i = 0; i < s.length; i++) {
                sb.append(s[i]);
            }

            set.add(sb.toString());
        }


        return set.size();
    }

    private List<String[]> searchBannedId(List<String[]> list, String[] banned_id) {
        List<String[]> ret = new ArrayList<>();

        for (String[] str : list) {
            boolean flag = true;
            for (int i = 0; i < str.length; i++) {
                if (!validateWord(str[i], banned_id[i])) {
                    flag = false;
                }
            }

            if (flag) {
                String[] s = new String[str.length];

                for (int i = 0; i < str.length; i++) {
                    s[i] = str[i];
                }

                ret.add(s);
            }
        }

        return ret;
    }

    private boolean validateWord(String word, String bannedWord) {
        if (word.length() != bannedWord.length()) {
            return false;
        }

        for (int i = 0; i < word.length(); i++) {
            if (bannedWord.charAt(i) == '*') {
                continue;
            }

            if (word.charAt(i) != bannedWord.charAt(i)) {
                return false;
            }
        }

        return true;
    }

    private void getList(int cnt, int limit, String[] userId, boolean[] visit) {
        if (cnt == limit) {
            String[] st = new String[strList.size()];
            for (int i = 0; i < strList.size(); i++) {
                st[i] = strList.get(i);
            }

            list.add(st);

            return;
        } else {
            for (int i = 0; i < userId.length; i++) {
                if (visit[i] == true) continue;
                visit[i] = true;
                strList.add(userId[i]);
                getList(cnt + 1, limit, userId, visit);
                visit[i] = false;
                strList.remove(strList.size() - 1);
            }
        }
    }
}