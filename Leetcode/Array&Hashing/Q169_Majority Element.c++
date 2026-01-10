class Solution {
public:
    int majorityElement(vector<int>& nums) {
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> mp;
        for(int n : nums) mp[n]++;
        for(auto& [n, c] : mp) pq.push({c, n});
        return pq.top().second;
    }
};
