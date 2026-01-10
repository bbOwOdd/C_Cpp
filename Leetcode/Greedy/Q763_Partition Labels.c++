class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26] = {0};
        int size = s.size();
        for(int i = 0; i < size; i++){
            last[s[i] - 'a'] = i;
        }
        vector<int> ans;
        int mx = 0, j = 0;
        for(int i = 0; i < size; i++){
            mx = max(mx, last[s[i] - 'a']);
            if(mx == i){
                ans.push_back(i - j + 1);
                j = i + 1;
            }
        }
        return ans;
    }
};
