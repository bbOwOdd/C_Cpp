class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int n : nums) pq.push(n);
        while(--k > 0) pq.pop();
        return pq.top();
    }
};
