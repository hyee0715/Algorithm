class Solution {
    private boolean check(String num) {
        if (num.length() == 0) {
            return true;
        }

        if (num.length() == 1) {
            if (!num.equals("0") && !num.equals("1") && !num.equals("8")) {
                return false;
            }
        }

        if (!(num.charAt(0) == '0' && num.charAt(num.length() - 1) == '0') && !(num.charAt(0) == '1' && num.charAt(num.length() - 1) == '1') && !(num.charAt(0) == '8' && num.charAt(num.length() - 1) == '8') && !(num.charAt(0) == '6' && num.charAt(num.length() - 1) == '9') && !(num.charAt(0) == '9' && num.charAt(num.length() - 1) == '6')) {
            return false;
        }

        if (num.length() >= 2 && !check(num.substring(1, num.length() - 1))) {
            return false;
        }

        return true;
    }

    public boolean isStrobogrammatic(String num) {
        if (check(num)) {
            return true;
        }

        return false;
    }
}