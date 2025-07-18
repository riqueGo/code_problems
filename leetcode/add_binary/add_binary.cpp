/*
 * Time Complexity: O(N)
 *   - N is the length of the longer input string.
 *   - Each character is processed once, and the result is reversed at the end (also O(N)).
 *
 * Space Complexity: O(N)
 *   - The result string can be at most N+1 in length (for a possible carry).
 *   - Additional space for leading zeros is also O(N).
 */

#include<string>
#include<algorithm>

using std::string;

class Solution {
public:
    string addBinary(string a, string b) {
        string leadingZeros = "";
        int diffLength = abs(int(a.length() - b.length()));
        for(int i = 0; i < diffLength; i++) leadingZeros += '0';

        if(a.length() < b.length()) a = leadingZeros + a;
        else b = leadingZeros + b;
        
        int carry = 0, bitA, bitB, sum, bit;
        string result = "";

        for(int i = a.length()-1; i >= 0; i--) {
            bitA = a[i] - '0';
            bitB = b[i] - '0';
            sum = bitA + bitB + carry;
            bit = sum%2;
            carry = sum/2;
            result += (char)(bit + '0');
        }

        if(carry) {
            result += (char)(carry+'0');
        }

        reverse(begin(result), end(result));
        return result;
    }
};

int main() {
    Solution s;
    s.addBinary("11", "1");
}