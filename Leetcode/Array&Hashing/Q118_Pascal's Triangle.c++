class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> a;
        a.push_back(vector<int>(1, 1));
        for(int i = 0; i < numRows - 1; i++){
            vector<int> b;
            b.push_back(1);
            for(int j = 0; j < a[i].size() - 1; j++){
                b.push_back(a[i][j] + a[i][j + 1]);
            }
            b.push_back(1);
            a.push_back(b);
        }
        return a;
    }
};
