package add_binary;

class Solution {
    public String addBinary(String a, String b) {
        int diffLength = Math.abs(a.length() - b.length());
        String leadingZeros = "";
        for(int i = 0; i < diffLength; i++) leadingZeros += '0';
        
        if(a.length() < b.length()) a = leadingZeros + a;
        else b = leadingZeros + b;

        int carry = 0, bitA, bitB, bit, sum;
        StringBuilder ans = new StringBuilder();
        for(int i = a.length()-1; i >= 0; i--) {
            bitA = a.charAt(i)-'0';
            bitB = b.charAt(i)-'0';
            sum = bitA + bitB + carry;
            bit = sum%2;
            carry = sum/2;
            ans.append(bit);
        }

        if(carry > 0) {
            ans.append(carry);
        }

        return ans.reverse().toString();
    }

    public static void main(String[] args) {
        Solution s = new Solution();
        s.addBinary("11", "1");
    }
}