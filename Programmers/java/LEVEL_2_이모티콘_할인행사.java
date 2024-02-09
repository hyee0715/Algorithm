import java.util.*;

class Solution {
    int[] rate = new int[]{10, 20, 30, 40};
    List<int[]> rateList = new ArrayList<>();

    public int[] solution(int[][] users, int[] emoticons) {
        int[] answer = new int[2];
        List<int[]> tempAnswer = new ArrayList<>();

        List<Integer> comb = new ArrayList<>();
        getDiscountRateDuplicatedCombination(0, emoticons.length, comb);

        for (int[] rate : rateList) {
            int[] discountedPrice = getDiscountedPrice(emoticons, rate);
            int totalPrice = 0;
            int totalMember = 0;

            for (int[] user : users) {
                int userRate = user[0];
                int userPrice = user[1];

                int priceSum = 0;
                for (int i = 0; i < rate.length; i++) {
                    if (rate[i] >= userRate) {
                        priceSum += discountedPrice[i];
                    }
                }

                if (priceSum >= userPrice) {
                    totalMember++;
                } else {
                    totalPrice += priceSum;
                }
            }

            tempAnswer.add(new int[]{totalMember, totalPrice});
        }

        sortAnswer(tempAnswer);

        answer = tempAnswer.get(0);
        return answer;
    }

    private void sortAnswer(List<int[]> answer) {
        Collections.sort(answer, (x, y) -> {
            if (x[0] < y[0]) {
                return 1;
            }

            if (x[0] > y[0]) {
                return -1;
            }

            if (x[1] < y[1]) {
                return 1;
            }

            if (x[1] > y[1]) {
                return -1;
            }

            return 0;
        });
    }

    private int[] getDiscountedPrice(int[] emoticons, int[] rate) {
        int[] discountedPrice = new int[rate.length];

        for (int i = 0; i < emoticons.length; i++) {
            discountedPrice[i] = (int)(emoticons[i] * (double)(100 - rate[i]) / 100);
        }

        return discountedPrice;
    }

    private void getDiscountRateDuplicatedCombination(int cnt, int limit, List<Integer> comb) {
        if (cnt == limit) {
            int[] list = new int[comb.size()];

            for (int i = 0; i < comb.size(); i++) {
                list[i] = comb.get(i);
            }

            rateList.add(list);

            return;
        } else {
            for (int i = 0; i < rate.length; i++) {
                comb.add(rate[i]);
                getDiscountRateDuplicatedCombination(cnt + 1, limit, comb);
                comb.remove(comb.size() - 1);
            }
        }
    }
}