class Solution {
public:
    int findComplement(int num) {
        int mask = 0, tmp = num;
        while(tmp){
            if(num == 0) return 1;
            mask = (mask << 1) | 1;
            tmp >>= 1;
        }
        return (~num) & mask;
    }
};
