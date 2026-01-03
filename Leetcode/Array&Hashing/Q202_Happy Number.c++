class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while (n != 1 && !s.count(n)) {
            s.insert(n);
            int tmp = 0;
            while(n) {
                tmp += (n % 10) * (n % 10);
                n /= 10;
            }
            n = tmp;
        }
        return n == 1;
    }
};
