class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = n - 1, j = n - 1;
        int cnt = 0, sum = 0;
        while (cnt < n) {
            sum += gas[j] - cost[j];
            cnt++;
            j = (j + 1) % n;
            while (sum < 0 && cnt < n) {
                i--;
                sum += gas[i] - cost[i];
                cnt++;
            }
        }
        return sum < 0 ? -1 : i;
    }
};
