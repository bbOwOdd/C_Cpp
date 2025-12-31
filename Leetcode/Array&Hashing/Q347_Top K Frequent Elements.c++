class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        using pii = pair<int, int>;
        for(int n : nums) ++map[n];

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for(auto& [n, c] : map){
            pq.push({c, n});
            if(pq.size() > k) pq.pop();
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }        
        return ans;
    }
};
