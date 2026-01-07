class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, int>> pq;
        for(int i = 0, size = points.size(); i < size; i++){
            double dist = hypot(points[i][0], points[i][1]);
            pq.push({dist, i});
            if(pq.size() > k) pq.pop();
        }

        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }

    // sort(points.begin(), points.end(), [](const vector<int>& p1, const vector<int>& p2) {
    //     return hypot(p1[0], p1[1]) < hypot(p2[0], p2[1]);
    // });
    // return vector<vector<int>>(points.begin(), points.begin() + k);
};
