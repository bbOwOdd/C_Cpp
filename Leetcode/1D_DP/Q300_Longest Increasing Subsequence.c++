class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> subset;
        for(int n : nums){
            auto it = lower_bound(subset.begin(), subset.end(), n);
            if(it != subset.end()) *it = n;
            else subset.push_back(n);
        }
        return subset.size();
    }
};
//patience sorting: greedy + binary search
//time complexity: O(nlogn)
//space complexity: O(n)
