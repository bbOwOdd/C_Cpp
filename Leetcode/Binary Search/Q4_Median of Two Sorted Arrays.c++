class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3(nums1.begin(), nums1.end());
        nums3.insert(nums3.end(), nums2.begin(), nums2.end());
        sort(nums3.begin(), nums3.end());

        int len = nums3.size();
        if(len % 2 == 0) return (nums3[len / 2] + nums3[len / 2 - 1]) / 2.0;
        else return nums3[len / 2];
    }
};
