class Solution {
    public String maximumOddBinaryNumber(String s) {
        int cnt1 = 0, cnt0 = 0;
        for (char a : s.toCharArray()) {
            if (a == '1') cnt1++;
            else if (a == '0') cnt0++;
        }
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < cnt1 - 1; i++) {
            ans.append("1");
        }
        for (int i = 0; i < cnt0; i++) {
            ans.append("0");
        }
        ans.append("1");
        return ans.toString();
    }
}
