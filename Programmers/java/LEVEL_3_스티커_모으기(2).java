class Solution {
    public int solution(int sticker[]) {
        int answer = 0;

        if (sticker.length == 1) {
            return sticker[0];
        }

        int[] dp1 = new int[sticker.length];
        int[] dp2 = new int[sticker.length];

        //첫번째 스티커 떼는 경우 (맨 마지막 sticker 원소는 체크하지 않음)
        dp1[0] = sticker[0];
        dp1[1] = dp1[0];

        for (int i = 2; i < sticker.length - 1; i++) {
            dp1[i] = Math.max(dp1[i - 2] + sticker[i], dp1[i - 1]);
        }

        //첫번째 스티커 떼지 않는 경우
        dp2[0] = 0;
        dp2[1] = dp2[0] + sticker[1];

        for (int i = 2; i < sticker.length; i++) {
            dp2[i] = Math.max(dp2[i - 2] + sticker[i], dp2[i - 1]);
        }

        answer = Math.max(dp1[dp1.length - 2], dp2[dp2.length - 1]);

        return answer;
    }
}