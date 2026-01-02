class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int x, int y){
            return position[x] > position[y];
        });

        int ans = 0;
        double pre = 0.0;
        for(int i : idx){
            double t = 1.0 * (target - position[i]) / speed[i];
            if(t > pre){
                pre = t;
                ans++;
            }
        }
        return ans;
    }
};
