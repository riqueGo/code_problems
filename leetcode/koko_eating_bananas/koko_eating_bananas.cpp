/*
Time Complexity:
    - canEat(): O(n) where n = number of piles
    - Binary search range: from 1 to max(piles), so O(log(maxPile))
    - Overall: O(n * log(maxPile))

Space Complexity:
    - O(1) extra space (only variables, no extra data structures)
*/

#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution {
private:
    bool canEat(const vector<int>& piles, const int& h, const int& k) {
        int hours = 0;
        for(int pile : piles) {
            hours += pile/k;
            if(pile % k != 0) hours++;
            if(hours > h) return false;
        }
        return hours <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = -1;
        for(int pile : piles) r = max(r, pile);

        int l = 1, m, ans;

        while(l <= r) {
            m = l + (r-l)/2;
            
            if(canEat(piles, h, m)) {
                ans = m;
                r = m-1;
            } else l = m+1;
        }

        return ans;
    }
};