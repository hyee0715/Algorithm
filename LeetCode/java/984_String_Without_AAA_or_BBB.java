class Solution {
    public String strWithout3a3b(int a, int b) {
        StringBuilder answer = new StringBuilder();
        boolean flag = false;

        if (a > b) {
            flag = true;
        }

        while (Math.abs(a - b) + 1 < b && Math.abs(a - b) + 1 < a) {
            if (flag) {
                answer.append("aabb");
            } else {
                answer.append("bbaa");
            }

            a -= 2;
            b -= 2;
        }

        if (a > b) {
            while (a >= 2 && b >= 1) {
                if (flag) {
                    answer.append("aab");
                }
                else {
                    answer.append("baa");
                }

                a -= 2;
                b -= 1;
            }
        }

        if (a < b) {
            while (a >= 1 && b >= 2) {
                if (flag) {
                    answer.append("abb");
                }
                else {
                    answer.append("bba");
                }

                a -= 1;
                b -= 2;
            }
        }

        if (flag) {
            while (a > 0) {
                answer.append("a");
                a--;
            }

            while (b > 0) {
                answer.append("b");
                b--;
            }
        }
        else {
            while (b > 0) {
                answer.append("b");
                b--;
            }

            while (a > 0) {
                answer.append("a");
                a--;
            }
        }

        return answer.toString();
    }
}