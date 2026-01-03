class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = ranges::max(piles);
        while(left < right){
            int middle = (left + right) >> 1;
            int s = 0;
            for(int x : piles) s += (x + middle - 1) / middle;
            if(s <= h) right = middle;
            else left = middle + 1;
        }
        return left;
    }
};
