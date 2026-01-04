class Solution {
public:
    int findDuplicate(vector<int>& nums) {        
        int slow = nums[0], fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);

        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;

        // unordered_map<int,int> map;
        // for(int i = 0; ; i++){
        //     if(map.contains(nums[i])) return nums[i];
        //     map[nums[i]] = i;
        // }

        // int l = 0, r = nums.size() - 1;
        // while (l < r) {
        //     int mid = (l + r) >> 1;
        //     int cnt = 0;
        //     for (int v : nums) cnt += v <= mid;
        //     if (cnt > mid) r = mid;
        //     else l = mid + 1;
        // }
        // return l;
    }
};
