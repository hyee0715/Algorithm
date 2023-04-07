class Solution {
    private int extractTime(String time) {
        int ret = 0;

        StringBuilder temp = new StringBuilder();
        temp.append(time.charAt(0));
        temp.append(time.charAt(1));

        ret += (Integer.parseInt(temp.toString()) * 60);

        temp.setLength(0);
        temp.append(time.charAt(3));
        temp.append(time.charAt(4));

        ret += Integer.parseInt(temp.toString());

        return ret;
    }

    public boolean haveConflict(String[] event1, String[] event2) {
        int event1Start = extractTime(event1[0]);
        int event1End = extractTime(event1[1]);

        int event2Start = extractTime(event2[0]);
        int event2End = extractTime(event2[1]);

        if (event1End == event2Start || event2End == event1Start || event1Start == event2Start || event1End == event2End) {
            return true;
        }

        if ((event2Start > event1Start && event2Start < event1End) || (event1Start > event2Start && event1Start < event2End)) {
            return true;
        }

        return false;
    }
}