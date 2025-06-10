#include <string>

using std::string;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int letters[26] = {0};
        for(char ch : magazine) {
            letters[ch-'a']++;
        }

        for(char ch : ransomNote) {
            if(!letters[ch-'a']--) return false;
        }
        return true;
    }
};