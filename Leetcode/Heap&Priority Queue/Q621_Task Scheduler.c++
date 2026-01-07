class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26);
        int mx = 0;
        for(char c : tasks){
            c -= 'A';
            cnt[c]++;
            mx = max(mx, cnt[c]);
        }

        int sum = 0;
        for(int n : cnt) sum += n == mx;
        return max((int) tasks.size(), (mx - 1) * (n + 1) + sum);
    }
};
